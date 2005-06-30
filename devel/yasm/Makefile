# ex:ts=8
# Ports collection makefile for:	yasm
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yasm
PORTVERSION=	0.4.0
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete rewrite of the NASM assembler

USE_REINPLACE=	yes
USE_ICONV=	yes
USE_LIBLTDL=	yes
USE_AUTOCONF_VER=259
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-man
MAN1=		yasm.1
MAN7=		yasm_arch.7
.endif

post-configure:
	@${REINPLACE_CMD} 's|$${top_builddir}/libltdl/libltdlc.la|-lltdl|' ${WRKSRC}/Makefile
	@${RM} -rf ${WRKSRC}/libltdl

.include <bsd.port.mk>
