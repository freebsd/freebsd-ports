# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gio2
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
CATEGORIES=	devel gnome ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	${RUBY_GNOME_DIST_SUBDIR}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding of GIO

BUILD_DEPENDS+=	${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/glib2.so:${PORTSDIR}/devel/ruby-glib2
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	glib20

CONFIGURE_ARGS=	--with-pkg-config-dir=${LOCALBASE}/libdata/pkgconfig

MASTERDIR=	${.CURDIR}/../../x11/ruby-gnome2
PKGDIR=		${.CURDIR}

DEPRECATED=	Use rubygem-gio2 instead
EXPIRATION_DATE=2014-03-23

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile.common"

WRKSRC=	${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install install

PORTDOCS=	README
DOCSDIR=	${RUBY_MODDOCDIR}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${RUBY_VER} != 1.9
BROKEN=		Does not work with Ruby 2.x
.endif

.include <bsd.port.post.mk>
