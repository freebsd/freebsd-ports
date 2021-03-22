--- vstgui4/vstgui/lib/platform/linux/cairofont.cpp.orig	2021-03-22 20:14:12 UTC
+++ vstgui4/vstgui/lib/platform/linux/cairofont.cpp
@@ -236,8 +236,7 @@ Font::Font (UTF8StringPtr name, const CCoord& size, co
 	auto it = map.find (name);
 	if (it == map.end ())
 	{
-		static constexpr auto defaults = {"Liberation Sans", "Noto Sans", "Ubuntu", "FreeSans"};
-		for (auto& defName : defaults)
+		for (auto& defName : {"Liberation Sans", "Noto Sans", "Ubuntu", "FreeSans"})
 		{
 			it = map.find (defName); // default font
 			if (it != map.end ())
