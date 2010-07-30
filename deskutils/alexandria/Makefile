# New ports collection makefile for:	Alexandria
# Date created:		18 March 2005
# Whom:			Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	alexandria
PORTVERSION=	0.6.6
CATEGORIES=	deskutils ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A GNOME application to help you manage your book collection

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake
RUN_DEPENDS=	${RUBY_SITELIBDIR}/gettext.rb:${PORTSDIR}/devel/ruby-gettext \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		${RUBY_SITEARCHLIBDIR:S/${PREFIX}/${LOCALBASE}/}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2 \
		rubygem-zoom>=0:${PORTSDIR}/devel/rubygem-zoom \
		rubygem-hpricot>=0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-htmlentities>=0:${PORTSDIR}/textproc/rubygem-htmlentities

USE_GNOME=	gnomehier intltool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_GETTEXT=	yes
USE_RUBY=	yes

MAN1=		alexandria.1

OPTIONS=	IMAGESIZE "Cover images optimization" off

.if !defined(NOPORTDOCS)
PORTDOCS=	README NEWS INSTALL TODO AUTHORS BUGS FAQ \
		cuecat_support.rdoc
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Rakefile-fixpaths
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Rakefile-fixpaths \
		${FILESDIR}/extra-patch-Rakefile-noportdocs
PORTDOCS=
.endif

GCONF_SCHEMAS=	alexandria.schemas

RUBY_REQUIRE=	Ruby > 180
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

USR2FIX=	Rakefile alexandria.desktop.in data/menu/alexandria \
		data/omf/alexandria/alexandria-C.omf \
		data/omf/alexandria/alexandria-fr.omf

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

.if defined(WITH_IMAGESIZE)
RUN_DEPENDS+=${RUBY_SITELIBDIR}/image_size.rb:${PORTSDIR}/graphics/ruby-image_size
.endif

pre-build:
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|' \
		${USR2FIX:S|^|${WRKSRC}/|}

do-build:
	@cd ${WRKSRC} && rake PREFIX=${PREFIX} build

do-install:
	@cd ${WRKSRC} && rake PREFIX=${PREFIX} install

.include <bsd.port.post.mk>
