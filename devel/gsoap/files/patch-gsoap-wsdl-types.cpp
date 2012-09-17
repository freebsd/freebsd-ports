--- gsoap/wsdl/types.cpp.orig
+++ gsoap/wsdl/types.cpp
@@ -1206,7 +1206,7 @@ void Types::gen(const char *URI, const char *name, const xs__simpleType& simpleT
               && simpleType.restriction->minExclusive
               && simpleType.restriction->minExclusive->value
               && is_integer(simpleType.restriction->minExclusive->value))
-          fprintf(stream, " "SOAP_LONG_FORMAT, to_integer(simpleType.restriction->minExclusive->value)+1);
+          fprintf(stream, " " SOAP_LONG_FORMAT, (long long) to_integer(simpleType.restriction->minExclusive->value)+1);
         if (!anonymous
          && simpleType.restriction->maxLength
          && simpleType.restriction->maxLength->value)
@@ -1228,7 +1228,7 @@ void Types::gen(const char *URI, const char *name, const xs__simpleType& simpleT
               && simpleType.restriction->maxExclusive
               && simpleType.restriction->maxExclusive->value
               && is_integer(simpleType.restriction->maxExclusive->value))
-          fprintf(stream, ":"SOAP_LONG_FORMAT, to_integer(simpleType.restriction->maxExclusive->value)-1);
+          fprintf(stream, ":" SOAP_LONG_FORMAT, (long long) to_integer(simpleType.restriction->maxExclusive->value)-1);
         if (!anonymous)
         { fprintf(stream, ";\n");
           if (pflag && simpleType.name)
@@ -2974,7 +2974,7 @@ static const char *utf8(char *t, const char *s)
             if (c < 0xFC)
               c = ((c & 0x03) << 24) | (c1 << 18) | (c2 << 12) | (c3 << 6) | c4;
             else
-              c = ((c & 0x01) << 30) | (c1 << 24) | (c2 << 18) | (c3 << 12) | (c4 << 6) | *++s & 0x3F;
+              c = ((c & 0x01) << 30) | (c1 << 24) | (c2 << 18) | (c3 << 12) | (c4 << 6) | (*++s & 0x3F);
           }
         }
       }
