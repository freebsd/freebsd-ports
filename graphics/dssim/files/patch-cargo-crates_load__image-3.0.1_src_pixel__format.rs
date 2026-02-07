--- cargo-crates/load_image-3.0.1/src/pixel_format.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/load_image-3.0.1/src/pixel_format.rs
@@ -49,24 +49,16 @@ pixel_format!{GrayAlpha<u8>, PixelFormat::GRAYA_8, Col
 pixel_format!{RGBA8, PixelFormat::RGBA_8, ColorSpaceSignature::RgbData }
 pixel_format!{Gray<u8>, PixelFormat::GRAY_8, ColorSpaceSignature::GrayData }
 pixel_format!{GrayAlpha<u8>, PixelFormat::GRAYA_8, ColorSpaceSignature::GrayData }
-#[cfg(target_endian = "little")]
 pixel_format!{RGB16, PixelFormat::RGB_16, ColorSpaceSignature::RgbData }
-#[cfg(target_endian = "little")]
 pixel_format!{RGBA16, PixelFormat::RGBA_16, ColorSpaceSignature::RgbData }
-#[cfg(target_endian = "little")]
 pixel_format!{Gray<u16>, PixelFormat::GRAY_16, ColorSpaceSignature::GrayData }
-#[cfg(target_endian = "little")]
 pixel_format!{GrayAlpha<u16>, PixelFormat::GRAYA_16, ColorSpaceSignature::GrayData }
 
 pixel_conversion!{RGB8 => RGB16, RGB16}
 pixel_conversion!{RGBA8 => RGBA16, RGB16}
 pixel_conversion!{Gray<u8> => Gray<u16>, Gray<u16>}
 pixel_conversion!{GrayAlpha<u8> => GrayAlpha<u16>, Gray<u16>}
-#[cfg(target_endian = "little")]
 pixel_conversion!{RGB16 => RGB16, RGB16}
-#[cfg(target_endian = "little")]
 pixel_conversion!{RGBA16 => RGBA16, RGB16}
-#[cfg(target_endian = "little")]
 pixel_conversion!{Gray<u16> => Gray<u16>, Gray<u16>}
-#[cfg(target_endian = "little")]
 pixel_conversion!{GrayAlpha<u16> => GrayAlpha<u16>, Gray<u16>}
