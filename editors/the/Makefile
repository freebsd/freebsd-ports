# New ports collection makefile for:	THE
# Date created:		7 May 1999
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	the
PORTVERSION=	3.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hessling-editor
DISTNAME=	THE-${PORTVERSION}

PATCH_SITES=	http://users.comlab.ox.ac.uk/ian.collier/distribution/
PATCHFILES=	${DISTNAME}-rexximc.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"The Hessling Editor", an implementation of the xedit editor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ncurses \
		--with-rexxincdir=${LOCALBASE}/include \
		--with-rexxlibdir=${LOCALBASE}/lib
ALL_TARGET=	all html

MAN1=		the.1

.if defined(WITH_REXX_REGINA)
BUILD_DEPENDS+=	regina:${PORTSDIR}/lang/rexx-regina
RUN_DEPENDS+=	regina:${PORTSDIR}/lang/rexx-regina
CONFIGURE_ARGS+=	--with-rexx=regina
.else
BUILD_DEPENDS+=	rexx:${PORTSDIR}/lang/rexx-imc
RUN_DEPENDS+=	rexx:${PORTSDIR}/lang/rexx-imc
CONFIGURE_ARGS+=	--with-rexx=rexximc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/THE
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/THE
.endif

.include <bsd.port.mk>
