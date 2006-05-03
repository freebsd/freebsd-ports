# Ports collection makefile for:  enca
# Date created:			  Fri Sep 20, 2002
# Whom:				  Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	enca
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	http://kf.fyz.fce.vutbr.cz/~yeti/Ftp/enca/

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	A package for detecting encoding of text files

USE_GNOME=	pkgconfig
USE_ICONV=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--without-librecode \
		--with-libiconv=${LOCALBASE}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

MAN1=	enca.1
MLINKS=	enca.1 enconv.1

post-patch::
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's#\ devel-docs##g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
