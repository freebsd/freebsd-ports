# New ports collection makefile for:	Ruby-qt2gl
# Date created:		7 Feb 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	qt2gl
PORTVERSION=	0.11
CATEGORIES=	graphics x11-toolkits ruby
MASTER_SITES=	http://sfns.u-shizuoka-ken.ac.jp/geneng/horie_hp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-qt2-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/qt2.so:${RUBY_QT2_PORTDIR} \
		${RUBY_SITEARCHLIBDIR}/opengl.so:${PORTSDIR}/graphics/ruby-opengl

RUBY_QT2_PORTDIR=	${PORTSDIR}/x11-toolkits/ruby-qt2

MD5_FILE=	${RUBY_QT2_PORTDIR}/distinfo

USE_MESA=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/qt2/modules/opengl
CONFIGURE_ARGS=	--with-qt2-include=${X11BASE}/include/qt2 \
		--with-qt2-lib=${X11BASE}/lib \
		--with-qt2=qt2 \
		--with-x11-dir=${X11BASE}
MAKE_ARGS=	LOCAL_LIBS=-lgcc
INSTALL_TARGET=	site-install

post-extract:
	find ${WRKSRC} '(' -name .cvsignore -o -name a.out ')' -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/qt2gl
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/qt2gl/
	${MKDIR} ${RUBY_DOCDIR}/qt2gl
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/qt2gl/
.endif

.include <bsd.port.mk>
