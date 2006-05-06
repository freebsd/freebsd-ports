" $FreeBSD$
" vim:ts=8
"
"   VIQR input
"
"	RFC 1456 Vietnamese Standardization Working Group,
"	Conventions for Encoding the Vietnamese Language
"	VISCII: VIetnamese Standard Code for Information Interchange
"	VIQR: VIetnamese Quoted-Readable Specification Revision 1.1",
"	May 1993.
"
set isprint=@,002,005-006,020,025,128-255
"
"letter Á
imap	A'	193
"letter À
imap	A`	192
"letter Ä
imap	A?	196
"letter Ã
imap	A~	195
"letter €
imap	A.	128
"letter Å
imap	A(	197
"letter 
imap	197'	129
"letter ‚
imap	197`	130
"letter 
imap	197?	002
"letter 
imap	197~	005
"letter ƒ
imap	197.	131
"letter Â
imap	A^	194
"letter „
imap	194'	132
"letter …
imap	194`	133
"letter †
imap	194?	134
"letter 
imap	194~	006
"letter ‡
imap	194.	135
"letter Ğ
imap	DD	208
imap	Dd	208
"letter É
imap	E'	201
"letter È
imap	E`	200
"letter Ë
imap	E?	203
"letter ˆ
imap	E~	136
"letter ‰
imap	E.	137
"letter Ê
imap	E^	202
"letter Š
imap	202'	138
"letter ‹
imap	202`	139
"letter Œ
imap	202?	140
"letter 
imap	202~	141
"letter 
imap	202.	142
"letter Í
imap	I'	205
"letter Ì
imap	I`	204
"letter ›
imap	I?	155
"letter Î
imap	I~	206
"letter ˜
imap	I.	152
"letter Ó
imap	O'	211
"letter Ò
imap	O`	210
"letter ™
imap	O?	153
"letter  
"imap	O~	213  -- bug in encoding  213 --> a.
imap	O~	160
"letter š
imap	O.	154
"letter Ô
imap	O^	212
"letter 
imap	212'	143
"letter 
imap	212`	144
"letter ‘
imap	212?	145
"letter ’
imap	212~	146
"letter “
imap	212.	147
"letter ´
imap	O+	180
"letter •
imap	180'	149
"letter –
imap	180`	150
"letter —
imap	180?	151
"letter ³
imap	180~	179
"letter ”
imap	180.	148
"letter Ú
imap	U'	218
"letter Ù
imap	U`	217
"letter œ
imap	U?	156
"letter 
imap	U~	157
"letter 
imap	U.	158
"letter ¿
imap	U+	191
"letter º
imap	191'	186
"letter »
imap	191`	187
"letter ¼
imap	191?	188
"letter ÿ
imap	191~	255
"letter ¹
imap	191.	185
"letter İ
imap	Y'	221
"letter Ÿ
imap	Y`	159
"letter 
imap	Y?	020
"letter 
imap	Y~	025
"letter 
imap	Y.	030
"letter á
imap	a'	225
"letter à
imap	a`	224
"letter ä
imap	a?	228
"letter ã
imap	a~	227
"letter Õ
"imap	a.	160  bug in encoding -- 160 --> O~
imap	a.	213
"letter å
imap	a(	229
"letter ¡
imap	229'	161
"letter ¢
imap	229`	162
"letter Æ
imap	229?	198
"letter Ç
imap	229~	199
"letter £
imap	229.	163
"letter â
imap	a^	226
"letter ¤
imap	226'	164
"letter ¥
imap	226`	165
"letter ¦
imap	226?	166
"letter ç
imap	226~	231
"letter §
imap	226.	167
"letter ğ
imap	dd	240
"letter é
imap	e'	233
"letter è
imap	e`	232
"letter ë
imap	e?	235
"letter ¨
imap	e~	168
"letter ©
imap	e.	169
"letter ê
imap	e^	234
"letter ª
imap	234'	170
"letter «
imap	234`	171
"letter ¬
imap	234?	172
"letter ­
imap	234~	173
"letter ®
imap	234.	174
"letter í
imap	i'	237
"letter ì
imap	i`	236
"letter ï
imap	i?	239
"letter î
imap	i~	238
"letter ¸
imap	i.	184
"letter ó
imap	o'	243
"letter ò
imap	o`	242
"letter ö
imap	o?	246
"letter õ
imap	o~	245
"letter ÷
imap	o.	247
"letter ô
imap	o^	244
"letter ¯
imap	244'	175
"letter °
imap	244`	176
"letter ±
imap	244?	177
"letter ²
imap	244~	178
"letter µ
imap	244.	181
"letter ½
imap	o+	189
"letter ¾
imap	189'	190
"letter ¶
imap	189`	182
"letter ·
imap	189?	183
"letter Ş
imap	189~	222
"letter ş
imap	189.	254
"letter ú
imap	u'	250
"letter ù
imap	u`	249
"letter ü
imap	u?	252
"letter û
imap	u~	251
"letter ø
imap	u.	248
"letter ß
imap	u+	223
"letter Ñ
imap	223'	209
"letter ×
imap	223`	215
"letter Ø
imap	223?	216
"letter æ
imap	223~	230
"letter ñ
imap	223.	241
"letter ı
imap	y'	253
"letter Ï
imap	y`	207
"letter Ö
imap	y?	214
"letter Û
imap	y~	219
"letter Ü
imap	y.	220
	"
	"	END OF VIQR input support
