--- basebmp/inc/basebmp/packedpixeliterator.hxx.orig	2019-08-14 17:37:07 UTC
+++ basebmp/inc/basebmp/packedpixeliterator.hxx
@@ -606,14 +606,17 @@ template< typename Valuetype,            (public)
                 >> get_shift<num_intraword_positions, bits_per_pixel, MsbFirst>(remainder)); 
     }
 
+/***** XXX - This appears to be unused and fails to compile with gcc9
     value_type get(difference_type const & d) const
     {
+//      XXX - should x(d.x) be (x + dx)?
         const int remainder( x(d.x) % num_intraword_positions );
 
         return (unsigned_cast<value_type>(*current(d.x,d.y) & 
                                           get_mask<value_type, bits_per_pixel, MsbFirst>(remainder))
                 >> get_shift<num_intraword_positions, bits_per_pixel, MsbFirst>(remainder)); 
     }
+******/
 
     void set( value_type v ) const
     {
