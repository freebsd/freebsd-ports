# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	3.0.6
PORTREVISION=	16
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-3.0/ \
		http://rpm.org/releases/historical/rpm-3.0.x/ \
		http://www.mirrorservice.org/sites/ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The Red Hat Package Manager

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt

OPTIONS_DEFINE=	NLS

CONFLICTS=	rpm-[45].* rpm[45]-*

USES=		gmake shebangfix
SHEBANG_FILES=	scripts/*
USE_AUTOTOOLS=	automake14 autoconf213 libtool
CONFIGURE_ARGS=	--with-glob
USE_LDCONFIG=	yes
MAKE_ENV=	OLD_PO_FILE_INPUT=1

OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lintl ${ICONV_LIB}"
NLS_CONFIGURE_ENABLE=	nls

post-patch:
.for file in rpm.c doc/rpm.8 lib/macro.c lib/rpmrc.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/gendiff.1 ${STAGEDIR}${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/doc/rpm.8 ${STAGEDIR}${PREFIX}/man/man8
		${INSTALL_MAN} ${WRKSRC}/doc/rpm2cpio.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
