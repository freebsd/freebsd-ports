# ex:ts=8
# New ports collection makefile for:	LeoArg
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	leoarg
PORTVERSION=	2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://home.pages.at/kingleo/development/
DISTNAME=	LeoArg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A class for parsing command lines

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN3=	LeoArg.3 LeoArg__InvalidOption.3 LeoArg__InvalidSetting.3 \
	LeoArg__Option.3 LeoArg__Setting.3 LeoArg_cpp.3 LeoArg_hh.3 \
	StringUtils_cpp.3 StringUtils_hh.3 namespace_StringUtils.3

post-patch:
.for file in Makefile.in doc/Makefile.in
	@${REINPLACE_CMD} -e 's|^docdir|#docdir|g ; \
		 s| install-data-local||g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for file in Makefile demo.sh leoargmain.cpp
	${INSTALL_DATA} ${WRKSRC}/example/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
