# New ports collection makefile for:	Ruby-qt2sound
# Date created:		13 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2sound
PORTVERSION=	${RUBY_QT2_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	audio x11-toolkits ruby
MASTER_SITES=	${RUBY_QT2_MASTER_SITES}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_QT2_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../x11-toolkits/ruby-qt2/Makefile.common"

WRKSRC=		${RUBY_QT2_WRKSRC}/modules/sound
CONFIGURE_ARGS=	${RUBY_QT2_CONFIGURE_ARGS}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

.include <bsd.port.post.mk>
