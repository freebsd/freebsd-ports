# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grzip
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/compression/ \
		https://BSDforge.com/projects/source/archivers/grzip/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Efficient file compressor

LICENSE=	LGPL21

USES=		tar:bzip2 gettext
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
ALL_TARGET=	${PORTNAME}
WRAPPERS=	grztar grzdiff grzgrep grzmore
PLIST_FILES=	bin/${PORTNAME} bin/grunzip bin/grzcat ${WRAPPERS:S|^|bin/|} \
		lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 include/${PORTNAME}.h \
		share/locale/fr/LC_MESSAGES/${PORTNAME}.mo

post-patch:
	@${REINPLACE_CMD} -e 's|DESTDIR|PREFIX|g;/^CC.*=/d;/^OPTFLAGS/s|-O2||;/^CFLAGS/s|=|+=|'\
		-e '/^PREFIX=/d;/^LDFLAGS/s|=|+=|' ${WRKSRC}/Makefile ${WRKSRC}/po/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/grunzip
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/grzcat
	${INSTALL_SCRIPT} ${WRAPPERS:S|^|${WRKSRC}/scripts/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib
	${LN} -sf lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	(cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} PREFIX="${STAGEDIR}${PREFIX}" install)

.include <bsd.port.mk>
