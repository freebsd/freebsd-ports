# New ports collection makefile for:	Ruby-qt2gl
# Date created:		7 Feb 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2gl
PORTVERSION=	${RUBY_QT2_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	graphics x11-toolkits ruby
MASTER_SITES=	${RUBY_QT2_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_QT2_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/opengl.so:${PORTSDIR}/graphics/ruby-opengl

USE_MESA=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_WITH_PTHREAD=	yes

USE_GMAKE=	yes

WRKSRC=		${RUBY_QT2_WRKSRC}/modules/opengl
CONFIGURE_ARGS=	${RUBY_QT2_CONFIGURE_ARGS:S/--with-qt2=qt2/--with-qt2=qtgl/}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-extract:
	find ${WRKSRC} '(' -name .cvsignore -o -name a.out ')' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include "${.CURDIR}/../../x11-toolkits/ruby-qt2/Makefile.common"
.include <bsd.port.mk>

DEPENDS_TARGET+=	RUBY_WITH_PTHREAD=yes
