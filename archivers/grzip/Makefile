# New ports collection makefile for:	grzip
# Date created:		02 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grzip
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/compression/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient file compressor

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
ALL_TARGET=	${PORTNAME}
WRAPPERS=	grztar grzdiff grzgrep grzmore
PLIST_FILES=	bin/${PORTNAME} bin/grunzip bin/grzcat ${WRAPPERS:S|^|bin/|} \
		lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.0 include/${PORTNAME}.h \
		share/locale/fr/LC_MESSAGES/${PORTNAME}.mo

post-patch:
	@${REINPLACE_CMD} -e 's|DESTDIR|PREFIX|g;/^CC.*=/d;/^OPTFLAGS/s|-O2||;/^CFLAGS/s|=|+=|'\
		-e '/^PREFIX=/d;/^LDFLAGS/s|=|+=|' ${WRKSRC}/Makefile ${WRKSRC}/po/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${LN} -sf ${PORTNAME} ${PREFIX}/bin/grunzip
	@${LN} -sf ${PORTNAME} ${PREFIX}/bin/grzcat
	@${INSTALL_SCRIPT} ${WRAPPERS:S|^|${WRKSRC}/scripts/|} ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/lib${PORTNAME}.so ${PREFIX}/lib/
	@${LN} -sf lib${PORTNAME}.so ${PREFIX}/lib/lib${PORTNAME}.so.0
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${PREFIX}/include/
	@cd ${WRKSRC}/po; ${SETENV} ${MAKE_ENV} ${MAKE} install

.include <bsd.port.mk>
