--- node.cc.orig	2009-10-04 14:01:21 UTC
+++ node.cc
@@ -175,7 +175,7 @@ Uint32 Node::colour() const
 	{
 	    intensity = (status == NODEST_NONE ? 0x80 : 0xbf);
 	    intensity += int( (0xff - intensity) *
-		    std::max(0.0, 1 - ( fabs(angleDiff(spin*3, 0)) * 2 )) );
+		    std::max(0.0f, 1 - ( fabsf(angleDiff(spin*3, 0)) * 2 )) );
 	}
     }
     else
