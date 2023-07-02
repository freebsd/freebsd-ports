--- src/common/exif.cc.orig	2023-02-15 16:52:33 UTC
+++ src/common/exif.cc
@@ -287,7 +287,7 @@ void dt_exif_set_exiv2_taglist()
     _get_xmp_tags("expressionmedia", &exiv2_taglist);
     _get_xmp_tags("MicrosoftPhoto", &exiv2_taglist);
   }
-  catch (Exiv2::AnyError& e)
+  catch (Exiv2::Error& e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 taglist] " << s << std::endl;
@@ -408,7 +408,7 @@ static void dt_remove_exif_keys(Exiv2::ExifData &exif,
       while((pos = exif.findKey(Exiv2::ExifKey(keys[i]))) != exif.end())
         exif.erase(pos);
     }
-    catch(Exiv2::AnyError &e)
+    catch(Exiv2::Error &e)
     {
       // the only exception we may get is "invalid" tag, which is not
       // important enough to either stop the function, or even display
@@ -428,7 +428,7 @@ static void dt_remove_xmp_keys(Exiv2::XmpData &xmp, co
       while((pos = xmp.findKey(Exiv2::XmpKey(keys[i]))) != xmp.end())
         xmp.erase(pos);
     }
-    catch(Exiv2::AnyError &e)
+    catch(Exiv2::Error &e)
     {
       // the only exception we may get is "invalid" tag, which is not
       // important enough to either stop the function, or even display
@@ -444,7 +444,7 @@ static bool dt_exif_read_xmp_tag(Exiv2::XmpData &xmpDa
   {
     return (*pos = xmpData.findKey(Exiv2::XmpKey(key))) != xmpData.end() && (*pos)->size();
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 read_xmp_tag] " << s << std::endl;
@@ -513,7 +513,7 @@ static bool _exif_decode_xmp_data(dt_image_t *img, Exi
 
     if(FIND_XMP_TAG("Xmp.xmp.Rating"))
     {
-      const int stars = pos->toLong();
+      const int stars = pos->toInt64();
       dt_image_set_xmp_rating(img, stars);
     }
     else
@@ -541,7 +541,7 @@ static bool _exif_decode_xmp_data(dt_image_t *img, Exi
       const int cnt = pos->count();
       for(int i = 0; i < cnt; i++)
       {
-        dt_colorlabels_set_label(img->id, pos->toLong(i));
+        dt_colorlabels_set_label(img->id, pos->toInt64(i));
       }
     }
 
@@ -610,7 +610,7 @@ static bool _exif_decode_xmp_data(dt_image_t *img, Exi
     imgs = NULL;
     return true;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     if(imgs) g_list_free(imgs);
     imgs = NULL;
@@ -626,7 +626,7 @@ static bool dt_exif_read_iptc_tag(Exiv2::IptcData &ipt
   {
     return (*pos = iptcData.findKey(Exiv2::IptcKey(key))) != iptcData.end() && (*pos)->size();
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 read_iptc_tag] " << s << std::endl;
@@ -684,7 +684,7 @@ static bool _exif_decode_iptc_data(dt_image_t *img, Ex
 
     return true;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 _exif_decode_iptc_data] " << img->filename << ": " << s << std::endl;
@@ -698,7 +698,7 @@ static bool _exif_read_exif_tag(Exiv2::ExifData &exifD
   {
     return (*pos = exifData.findKey(Exiv2::ExifKey(key))) != exifData.end() && (*pos)->size();
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 read_exif_tag] " << s << std::endl;
@@ -761,17 +761,17 @@ static gboolean _check_lens_correction_data(Exiv2::Exi
     && _exif_read_exif_tag(exifData, &posv, "Exif.SubImage1.VignettingCorrParams"))
   {
     // Validate
-    const int nc = posd->toLong(0);
-    if(nc <= 16 && 2*nc == posc->toLong(0) && nc == posv->toLong(0))
+    const int nc = posd->toInt64(0);
+    if(nc <= 16 && 2*nc == posc->toInt64(0) && nc == posv->toInt64(0))
     {
       img->exif_correction_type = CORRECTION_TYPE_SONY;
       img->exif_correction_data.sony.nc = nc;
       for(int i = 0; i < nc; i++)
       {
-        img->exif_correction_data.sony.distortion[i] = posd->toLong(i + 1);
-        img->exif_correction_data.sony.ca_r[i] = posc->toLong(i + 1);
-        img->exif_correction_data.sony.ca_b[i] = posc->toLong(nc + i + 1);
-        img->exif_correction_data.sony.vignetting[i] = posv->toLong(i + 1);
+        img->exif_correction_data.sony.distortion[i] = posd->toInt64(i + 1);
+        img->exif_correction_data.sony.ca_r[i] = posc->toInt64(i + 1);
+        img->exif_correction_data.sony.ca_b[i] = posc->toInt64(nc + i + 1);
+        img->exif_correction_data.sony.vignetting[i] = posv->toInt64(i + 1);
       }
     }
   }
@@ -807,7 +807,7 @@ static gboolean _check_lens_correction_data(Exiv2::Exi
       }
 
       // Account for the 1.25x crop modes in some Fuji cameras
-      if(FIND_EXIF_TAG("Exif.Fujifilm.CropMode") && (pos->toLong() == 2 || pos->toLong() == 4))
+      if(FIND_EXIF_TAG("Exif.Fujifilm.CropMode") && (pos->toInt64() == 2 || pos->toInt64() == 4))
         img->exif_correction_data.fuji.cropf = 1.25f;
       else
         img->exif_correction_data.fuji.cropf = 1;
@@ -833,7 +833,7 @@ void dt_exif_img_check_additional_tags(dt_image_t *img
     }
     return;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 reading DefaultUserCrop] " << filename << ": " << s << std::endl;
@@ -1110,11 +1110,11 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
      */
     if(FIND_EXIF_TAG("Exif.Image.Orientation"))
     {
-      img->orientation = dt_image_orientation_to_flip_bits(pos->toLong());
+      img->orientation = dt_image_orientation_to_flip_bits(pos->toInt64());
     }
     else if(FIND_EXIF_TAG("Exif.PanasonicRaw.Orientation"))
     {
-      img->orientation = dt_image_orientation_to_flip_bits(pos->toLong());
+      img->orientation = dt_image_orientation_to_flip_bits(pos->toInt64());
     }
 
     /* read gps location */
@@ -1163,9 +1163,9 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
 
     /* Read lens name */
     if((FIND_EXIF_TAG("Exif.CanonCs.LensType")
-        && pos->toLong() != 61182   // prefer the other tag for RF lenses
-        && pos->toLong() != 0
-        && pos->toLong() != 65535)
+        && pos->toInt64() != 61182   // prefer the other tag for RF lenses
+        && pos->toInt64() != 0
+        && pos->toInt64() != 65535)
        || FIND_EXIF_TAG("Exif.Canon.LensModel"))
     {
       dt_strlcpy_to_utf8(img->exif_lens, sizeof(img->exif_lens), pos, exifData);
@@ -1203,7 +1203,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
         fprintf(stderr, "[exif] Warning: lens \"%s\" unknown as \"%s\"\n", img->exif_lens, lens.c_str());
       }
     }
-    else if(Exiv2::testVersion(0,27,4) && FIND_EXIF_TAG("Exif.NikonLd4.LensID") && pos->toLong() == 0)
+    else if(Exiv2::testVersion(0,27,4) && FIND_EXIF_TAG("Exif.NikonLd4.LensID") && pos->toInt64() == 0)
     {
       /* Z body w/ FTZ adapter or recent F body (e.g. D780, D6) detected.
        * Prioritize the legacy ID lookup instead of Exif.Photo.LensModel included
@@ -1295,12 +1295,12 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
     {
       if(FIND_EXIF_TAG("Exif.Image.Rating"))
       {
-        const int stars = pos->toLong();
+        const int stars = pos->toInt64();
         dt_image_set_xmp_rating(img, stars);
       }
       else if(FIND_EXIF_TAG("Exif.Image.RatingPercent"))
       {
-        const int stars = pos->toLong() * 5. / 100;
+        const int stars = pos->toInt64() * 5. / 100;
         dt_image_set_xmp_rating(img, stars);
       }
       else
@@ -1355,7 +1355,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
       {
         for(int i = 0; i < 9; i++) colmatrix[0][i] = cm1_pos->toFloat(i);
 
-        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant1")) illu[0] = (dt_dng_illuminant_t) pos->toLong();
+        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant1")) illu[0] = (dt_dng_illuminant_t) pos->toInt64();
       }
 
       Exiv2::ExifData::const_iterator cm2_pos = exifData.findKey(Exiv2::ExifKey("Exif.Image.ColorMatrix2"));
@@ -1363,7 +1363,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
       {
         for(int i = 0; i < 9; i++) colmatrix[1][i] = cm2_pos->toFloat(i);
 
-        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant2")) illu[1] = (dt_dng_illuminant_t) pos->toLong();
+        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant2")) illu[1] = (dt_dng_illuminant_t) pos->toInt64();
       }
 
       // So far the Exif.Image.CalibrationIlluminant3 tag and friends have not been implemented and there are no images to test
@@ -1373,7 +1373,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
       {
         for(int i = 0; i < 9; i++) colmatrix[2][i] = cm3_pos->toFloat(i);
 
-        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant3")) illu[2] = (dt_dng_illuminant_t) pos->toLong();
+        if(FIND_EXIF_TAG("Exif.Image.CalibrationIlluminant3")) illu[2] = (dt_dng_illuminant_t) pos->toInt64();
       }
 #endif
 
@@ -1494,18 +1494,18 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
       int phi = 0;
 
       if(FIND_EXIF_TAG("Exif.SubImage1.SampleFormat"))
-        format = pos->toLong();
+        format = pos->toInt64();
       else if(FIND_EXIF_TAG("Exif.Image.SampleFormat"))
-        format = pos->toLong();
+        format = pos->toInt64();
 
       if(FIND_EXIF_TAG("Exif.SubImage1.BitsPerSample"))
-        bps = pos->toLong();
+        bps = pos->toInt64();
 
       if(FIND_EXIF_TAG("Exif.SubImage1.SamplesPerPixel"))
-        spp = pos->toLong();
+        spp = pos->toInt64();
 
       if(FIND_EXIF_TAG("Exif.SubImage1.PhotometricInterpretation"))
-        phi = pos->toLong();
+        phi = pos->toInt64();
 
       if((format == 3) && (bps >= 16) && (((spp == 1) && (phi == 32803)) || ((spp == 3) && (phi == 34892)))) is_hdr = TRUE;
       if((format == 1) && (bps == 16) && (spp == 1) && (phi == 34892)) is_monochrome = TRUE;
@@ -1528,7 +1528,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
     //          + Exif.Iop.InteroperabilityIndex of 'R98' -> sRGB
     if(dt_image_is_ldr(img) && FIND_EXIF_TAG("Exif.Photo.ColorSpace"))
     {
-      int colorspace = pos->toLong();
+      int colorspace = pos->toInt64();
       if(colorspace == 0x01)
         img->colorspace = DT_IMAGE_COLORSPACE_SRGB;
       else if(colorspace == 0x02)
@@ -1547,7 +1547,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
     }
 
     // Improve lens detection for Sony SAL lenses.
-    if(FIND_EXIF_TAG("Exif.Sony2.LensID") && pos->toLong() != 65535 && pos->print().find('|') == std::string::npos)
+    if(FIND_EXIF_TAG("Exif.Sony2.LensID") && pos->toInt64() != 65535 && pos->print().find('|') == std::string::npos)
     {
       dt_strlcpy_to_utf8(img->exif_lens, sizeof(img->exif_lens), pos, exifData);
     }
@@ -1569,7 +1569,7 @@ static bool _exif_decode_exif_data(dt_image_t *img, Ex
     img->exif_inited = 1;
     return true;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 _exif_decode_exif_data] " << img->filename << ": " << s << std::endl;
@@ -1645,7 +1645,7 @@ int dt_exif_read_from_blob(dt_image_t *img, uint8_t *b
     dt_exif_apply_default_metadata(img);
     return res ? 0 : 1;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_read_from_blob] " << img->filename << ": " << s << std::endl;
@@ -1696,7 +1696,7 @@ int dt_exif_get_thumbnail(const char *path, uint8_t **
 
     return 0;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_get_thumbnail] " << path << ": " << s << std::endl;
@@ -1765,7 +1765,7 @@ int dt_exif_read(dt_image_t *img, const char *path)
 
     return res ? 0 : 1;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_read] " << path << ": " << s << std::endl;
@@ -1822,7 +1822,7 @@ int dt_exif_write_blob(uint8_t *blob, uint32_t size, c
     imgExifData.sortByTag();
     image->writeMetadata();
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_write_blob] " << path << ": " << s << std::endl;
@@ -2151,7 +2151,7 @@ int dt_exif_read_blob(uint8_t **buf, const char *path,
     memcpy(*buf, &(blob[0]), length);
     return length;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     // std::cerr.rdbuf(savecerr);
     std::string s(e.what());
@@ -2662,16 +2662,16 @@ static GList *read_history_v2(Exiv2::XmpData &xmpData,
       }
       else if(g_str_has_prefix(key_iter, "darktable:num"))
       {
-        current_entry->num = history->value().toLong();
+        current_entry->num = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:enabled"))
       {
-        current_entry->enabled = history->value().toLong() == 1;
+        current_entry->enabled = history->value().toInt64() == 1;
       }
       else if(g_str_has_prefix(key_iter, "darktable:modversion"))
       {
         current_entry->have_modversion = TRUE;
-        current_entry->modversion = history->value().toLong();
+        current_entry->modversion = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:params"))
       {
@@ -2685,7 +2685,7 @@ static GList *read_history_v2(Exiv2::XmpData &xmpData,
       }
       else if(g_str_has_prefix(key_iter, "darktable:multi_priority"))
       {
-        current_entry->multi_priority = history->value().toLong();
+        current_entry->multi_priority = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:iop_order"))
       {
@@ -2698,7 +2698,7 @@ static GList *read_history_v2(Exiv2::XmpData &xmpData,
       }
       else if(g_str_has_prefix(key_iter, "darktable:blendop_version"))
       {
-        current_entry->blendop_version = history->value().toLong();
+        current_entry->blendop_version = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:blendop_params"))
       {
@@ -2772,22 +2772,22 @@ static GHashTable *read_masks(Exiv2::XmpData &xmpData,
         mask_entry_t *entry = (mask_entry_t *)calloc(1, sizeof(mask_entry_t));
 
         entry->version = version;
-        entry->mask_id = mask_id->toLong(i);
-        entry->mask_type = mask_type->toLong(i);
+        entry->mask_id = mask_id->toInt64(i);
+        entry->mask_type = mask_type->toInt64(i);
         std::string mask_name_str = mask_name->toString(i);
         if(mask_name_str.c_str() != NULL)
           entry->mask_name = g_strdup(mask_name_str.c_str());
         else
           entry->mask_name = g_strdup("form");
 
-        entry->mask_version = mask_version->toLong(i);
+        entry->mask_version = mask_version->toInt64(i);
 
         std::string mask_str = mask->toString(i);
         const char *mask_c = mask_str.c_str();
         const size_t mask_c_len = strlen(mask_c);
         entry->mask_points = dt_exif_xmp_decode(mask_c, mask_c_len, &entry->mask_points_len);
 
-        entry->mask_nb = mask_nb->toLong(i);
+        entry->mask_nb = mask_nb->toInt64(i);
 
         std::string mask_src_str = mask_src->toString(i);
         const char *mask_src_c = mask_src_str.c_str();
@@ -2858,15 +2858,15 @@ static GList *read_masks_v3(Exiv2::XmpData &xmpData, c
       // go on reading things into current_entry
       if(g_str_has_prefix(key_iter, "darktable:mask_num"))
       {
-        current_entry->mask_num = history->value().toLong();
+        current_entry->mask_num = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_id"))
       {
-        current_entry->mask_id = history->value().toLong();
+        current_entry->mask_id = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_type"))
       {
-        current_entry->mask_type = history->value().toLong();
+        current_entry->mask_type = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_name"))
       {
@@ -2874,7 +2874,7 @@ static GList *read_masks_v3(Exiv2::XmpData &xmpData, c
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_version"))
       {
-        current_entry->mask_version = history->value().toLong();
+        current_entry->mask_version = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_points"))
       {
@@ -2882,7 +2882,7 @@ static GList *read_masks_v3(Exiv2::XmpData &xmpData, c
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_nb"))
       {
-        current_entry->mask_nb = history->value().toLong();
+        current_entry->mask_nb = history->value().toInt64();
       }
       else if(g_str_has_prefix(key_iter, "darktable:mask_src"))
       {
@@ -3034,7 +3034,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
 
     int num_masks = 0;
     if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.xmp_version"))) != xmpData.end())
-      xmp_version = pos->toLong();
+      xmp_version = pos->toInt64();
 
     if(!history_only)
     {
@@ -3052,7 +3052,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
           int32_t in;
           dt_image_raw_parameters_t out;
       } raw_params;
-      raw_params.in = pos->toLong();
+      raw_params.in = pos->toInt64();
       const int32_t user_flip = raw_params.out.user_flip;
       img->legacy_flip.user_flip = user_flip;
       img->legacy_flip.legacy = 0;
@@ -3062,7 +3062,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
 
     if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.auto_presets_applied"))) != xmpData.end())
     {
-      preset_applied = pos->toLong();
+      preset_applied = pos->toInt64();
 
       // in any case, this is no legacy image.
       img->flags |= DT_IMAGE_NO_LEGACY_PRESETS;
@@ -3085,7 +3085,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
     {
       if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.iop_order_version"))) != xmpData.end())
       {
-        iop_order_version = (dt_iop_order_t)pos->toLong();
+        iop_order_version = (dt_iop_order_t)pos->toInt64();
       }
 
       if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.iop_order_list"))) != xmpData.end())
@@ -3103,7 +3103,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
       {
         //  All iop-order version before 3 are legacy one. Starting with version 3 we have the first
         //  attempts to propose the final v3 iop-order.
-        iop_order_version = pos->toLong() < 3 ? DT_IOP_ORDER_LEGACY : DT_IOP_ORDER_V30;
+        iop_order_version = pos->toInt64() < 3 ? DT_IOP_ORDER_LEGACY : DT_IOP_ORDER_V30;
         iop_order_list = dt_ioppr_get_iop_order_list_version(iop_order_version);
       }
       else
@@ -3355,7 +3355,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
     // we shouldn't change history_end when no history was read!
     if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.history_end"))) != xmpData.end() && num > 0)
     {
-      int history_end = MIN(pos->toLong(), num);
+      int history_end = MIN(pos->toInt64(), num);
       if(num_masks > 0) history_end++;
       if((history_end < 1) && preset_applied) preset_applied = -1;
       DT_DEBUG_SQLITE3_PREPARE_V2(dt_database_get(darktable.db),
@@ -3471,7 +3471,7 @@ int dt_exif_xmp_read(dt_image_t *img, const char *file
     }
 
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     // actually nobody's interested in that if the file doesn't exist:
     // std::string s(e.what());
@@ -3677,23 +3677,23 @@ void read_xmp_timestamps(Exiv2::XmpData &xmpData, dt_i
   if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.change_timestamp"))) != xmpData.end())
   {
     if(xmp_version > 5)
-      img->change_timestamp = pos->toLong();
-    else if(pos->toLong() >= 1)
-      img->change_timestamp = _convert_unix_to_gtimespan(pos->toLong());
+      img->change_timestamp = pos->toInt64();
+    else if(pos->toInt64() >= 1)
+      img->change_timestamp = _convert_unix_to_gtimespan(pos->toInt64());
   }
   if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.export_timestamp"))) != xmpData.end())
   {
     if(xmp_version > 5)
-      img->export_timestamp = pos->toLong();
-    else if(pos->toLong() >= 1)
-      img->export_timestamp = _convert_unix_to_gtimespan(pos->toLong());
+      img->export_timestamp = pos->toInt64();
+    else if(pos->toInt64() >= 1)
+      img->export_timestamp = _convert_unix_to_gtimespan(pos->toInt64());
   }
   if((pos = xmpData.findKey(Exiv2::XmpKey("Xmp.darktable.print_timestamp"))) != xmpData.end())
   {
     if(xmp_version > 5)
-      img->print_timestamp = pos->toLong();
-    else if(pos->toLong() >= 1)
-      img->print_timestamp = _convert_unix_to_gtimespan(pos->toLong());
+      img->print_timestamp = pos->toInt64();
+    else if(pos->toInt64() >= 1)
+      img->print_timestamp = _convert_unix_to_gtimespan(pos->toInt64());
   }
 }
 
@@ -4060,7 +4060,7 @@ char *dt_exif_xmp_read_string(const int imgid)
       std::string xmpPacket;
 
       Exiv2::DataBuf buf = Exiv2::readFile(WIDEN(input_filename));
-      xmpPacket.assign(reinterpret_cast<char *>(buf.pData_), buf.size_);
+      xmpPacket.assign(reinterpret_cast<const char *>(buf.c_data()), buf.size());
       Exiv2::XmpParser::decode(xmpData, xmpPacket);
       // because XmpSeq or XmpBag are added to the list, we first have
       // to remove these so that we don't end up with a string of duplicates
@@ -4076,7 +4076,7 @@ char *dt_exif_xmp_read_string(const int imgid)
       std::string xmpPacket;
 
       Exiv2::DataBuf buf = Exiv2::readFile(WIDEN(input_filename));
-      xmpPacket.assign(reinterpret_cast<char *>(buf.pData_), buf.size_);
+      xmpPacket.assign(reinterpret_cast<const char *>(buf.c_data()), buf.size());
       Exiv2::XmpParser::decode(sidecarXmpData, xmpPacket);
 
       for(Exiv2::XmpData::const_iterator it = sidecarXmpData.begin(); it != sidecarXmpData.end(); ++it)
@@ -4098,7 +4098,7 @@ char *dt_exif_xmp_read_string(const int imgid)
     }
     return g_strdup(xmpPacket.c_str());
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::cerr << "[xmp_read_blob] caught exiv2 exception '" << e << "'\n";
     return NULL;
@@ -4113,7 +4113,7 @@ static void dt_remove_xmp_key(Exiv2::XmpData &xmp, con
     if(pos != xmp.end())
       xmp.erase(pos);
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
   }
 }
@@ -4131,7 +4131,7 @@ static void _remove_xmp_keys(Exiv2::XmpData &xmpData, 
         ++i;
     }
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
   }
 }
@@ -4144,7 +4144,7 @@ static void dt_remove_exif_key(Exiv2::ExifData &exif, 
     if(pos != exif.end())
       exif.erase(pos);
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
   }
 }
@@ -4157,7 +4157,7 @@ static void dt_remove_iptc_key(Exiv2::IptcData &iptc, 
     while((pos = iptc.findKey(Exiv2::IptcKey(key))) != iptc.end())
       iptc.erase(pos);
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
   }
 }
@@ -4188,7 +4188,7 @@ int dt_exif_xmp_attach_export(const int imgid, const c
         img->setXmpData(input_image->xmpData());
       }
     }
-    catch(Exiv2::AnyError &e)
+    catch(Exiv2::Error &e)
     {
       std::cerr << "[xmp_attach] " << input_filename << ": caught exiv2 exception '" << e << "'\n";
     }
@@ -4204,7 +4204,7 @@ int dt_exif_xmp_attach_export(const int imgid, const c
       std::string xmpPacket;
 
       Exiv2::DataBuf buf = Exiv2::readFile(WIDEN(input_filename));
-      xmpPacket.assign(reinterpret_cast<char *>(buf.pData_), buf.size_);
+      xmpPacket.assign(reinterpret_cast<const char *>(buf.c_data()), buf.size());
       Exiv2::XmpParser::decode(sidecarXmpData, xmpPacket);
 
       for(Exiv2::XmpData::const_iterator it = sidecarXmpData.begin(); it != sidecarXmpData.end(); ++it)
@@ -4368,10 +4368,10 @@ int dt_exif_xmp_attach_export(const int imgid, const c
     {
       img->writeMetadata();
     }
-    catch(Exiv2::AnyError &e)
+    catch(Exiv2::Error &e)
     {
 #if EXIV2_TEST_VERSION(0,27,0)
-      if(e.code() == Exiv2::kerTooLargeJpegSegment)
+      if(e.code() == Exiv2::ErrorCode::kerTooLargeJpegSegment)
 #else
       if(e.code() == 37)
 #endif
@@ -4384,7 +4384,7 @@ int dt_exif_xmp_attach_export(const int imgid, const c
         {
           img->writeMetadata();
         }
-        catch(Exiv2::AnyError &e2)
+        catch(Exiv2::Error &e2)
         {
           std::cerr << "[dt_exif_xmp_attach_export] without history " << filename << ": caught exiv2 exception '" << e2 << "'\n";
           return -1;
@@ -4395,7 +4395,7 @@ int dt_exif_xmp_attach_export(const int imgid, const c
     }
     return 0;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::cerr << "[dt_exif_xmp_attach_export] " << filename << ": caught exiv2 exception '" << e << "'\n";
     return -1;
@@ -4437,7 +4437,7 @@ int dt_exif_xmp_write(const int imgid, const char *fil
       }
 
       Exiv2::DataBuf buf = Exiv2::readFile(WIDEN(filename));
-      xmpPacket.assign(reinterpret_cast<char *>(buf.pData_), buf.size_);
+      xmpPacket.assign(reinterpret_cast<const char *>(buf.c_data()), buf.size());
       Exiv2::XmpParser::decode(xmpData, xmpPacket);
       // because XmpSeq or XmpBag are added to the list, we first have
       // to remove these so that we don't end up with a string of duplicates
@@ -4492,7 +4492,7 @@ int dt_exif_xmp_write(const int imgid, const char *fil
 
     return 0;
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::cerr << "[dt_exif_xmp_write] " << filename << ": caught exiv2 exception '" << e << "'\n";
     return -1;
@@ -4515,7 +4515,7 @@ dt_colorspaces_color_profile_type_t dt_exif_get_color_
     // clang-format on
     if((pos = exifData.findKey(Exiv2::ExifKey("Exif.Photo.ColorSpace"))) != exifData.end() && pos->size())
     {
-      int colorspace = pos->toLong();
+      int colorspace = pos->toInt64();
       if(colorspace == 0x01)
         return DT_COLORSPACE_SRGB;
       else if(colorspace == 0x02)
@@ -4536,7 +4536,7 @@ dt_colorspaces_color_profile_type_t dt_exif_get_color_
 
     return DT_COLORSPACE_DISPLAY; // nothing embedded
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_get_color_space] " << s << std::endl;
@@ -4556,7 +4556,7 @@ void dt_exif_get_basic_data(const uint8_t *data, size_
     _find_datetime_taken(exifData, pos, basic_exif->datetime);
     _find_exif_makermodel(exifData, pos, basic_exif);
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     std::string s(e.what());
     std::cerr << "[exiv2 dt_exif_get_basic_data] " << s << std::endl;
@@ -4590,7 +4590,7 @@ void dt_exif_init()
   {
     Exiv2::XmpProperties::propertyList("lr");
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     // if lightroom is not known register it
     Exiv2::XmpProperties::registerNs("http://ns.adobe.com/lightroom/1.0/", "lr");
@@ -4599,7 +4599,7 @@ void dt_exif_init()
   {
     Exiv2::XmpProperties::propertyList("exifEX");
   }
-  catch(Exiv2::AnyError &e)
+  catch(Exiv2::Error &e)
   {
     // if exifEX is not known register it
     Exiv2::XmpProperties::registerNs("http://cipa.jp/exif/1.0/", "exifEX");
