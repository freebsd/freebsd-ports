# New ports collection makefile for:	kon2 with 16dot font
# Date created:         31 March 2003
# Whom:                 Chen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTREVISION=	1

MASTERDIR=	${.CURDIR}/../../japanese/kon2-16dot
EXTRA_PATCHES=	${.CURDIR}/files/patch-lib::coding.c
CATEGORIES=	chinese

MAINTAINER=	statue@freebsd.netlab.cse.yzu.edu.tw

BUILD_DEPENDS+=	${LOCALBASE}/share/fonts/bdf/kc15f.bdf.gz:${PORTSDIR}/chinese/kcfonts:patch

USE_REINPLACE=	yes
PLIST=		pkg-plist
KCFONTS_WRKSRC=	`cd ${PORTSDIR}/chinese/kcfonts; make -V WRKSRC`

post-patch:
	${REINPLACE_CMD} -e "s;jiskan16.bdf.gz;kc15f.bdf.gz;g" \
		-e "s;ja_JP.ujis:Coding;ja_JP.ujis:;g" \
		-e "s;zh_TW.big5:;zh_TW.big5:Coding;g" \
		-e "s;BIG5.HKU-0;BIG5-0;g" \
		-e "s,GB2312.1980,GBK,g" \
		${WRKSRC}/kon.cfg.FreeBSD
	${REINPLACE_CMD} -e "s;BIG5.HKU-0;BIG5-0;g" \
		-e "s;BIG5,      0;BIG5, 0xfefe;g" \
		-e "s,GB2312.1980,GBK,g" \
		${WRKSRC}/lib/coding.c
	${REINPLACE_CMD} -e 's,/dev/vga,/dev/ttyv0,g' ${WRKSRC}/src/term.c \
		${WRKSRC}/src/display/vga.c

pre-install:
	${MKDIR} ${PREFIX}/share/fonts/bdf
	cd ${KCFONTS_WRKSRC} && gcc -O -pipe -o kc15f tran.c kc15f.c && \
		./kc15f | ${GZIP_CMD} - > ${PREFIX}/share/fonts/bdf/kc15f.bdf.gz

.include "${MASTERDIR}/Makefile"
