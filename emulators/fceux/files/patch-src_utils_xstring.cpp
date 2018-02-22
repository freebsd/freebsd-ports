--- src/utils/xstring.cpp.orig	2018-02-21 20:25:04 UTC
+++ src/utils/xstring.cpp
@@ -231,8 +231,8 @@ std::string BytesToString(const void* data, int len)
 			{
 				Base64Table[ input[0] >> 2 ],
 				Base64Table[ ((input[0] & 0x03) << 4) | (input[1] >> 4) ],
-				n<2 ? '=' : Base64Table[ ((input[1] & 0x0F) << 2) | (input[2] >> 6) ],
-				n<3 ? '=' : Base64Table[ input[2] & 0x3F ]
+				static_cast<unsigned char>( n<2 ? '=' : Base64Table[ ((input[1] & 0x0F) << 2) | (input[2] >> 6) ] ),
+				static_cast<unsigned char>( n<3 ? '=' : Base64Table[ input[2] & 0x3F ] )
 			};
 			ret.append(output, output+4);
 		}
@@ -296,9 +296,9 @@ bool StringToBytes(const std::string& str, void* data,
 			}
 			unsigned char outpacket[3] =
 			{
-				(converted[0] << 2) | (converted[1] >> 4),
-				(converted[1] << 4) | (converted[2] >> 2),
-				(converted[2] << 6) | (converted[3])
+				static_cast<unsigned char>( (converted[0] << 2) | (converted[1] >> 4) ),
+				static_cast<unsigned char>( (converted[1] << 4) | (converted[2] >> 2) ),
+				static_cast<unsigned char>( (converted[2] << 6) | (converted[3]) )
 			};
 			int outlen = (input[2] == '=') ? 1 : (input[3] == '=' ? 2 : 3);
 			if(outlen > len) outlen = len;
