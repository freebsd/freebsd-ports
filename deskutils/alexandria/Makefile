# New ports collection makefile for:	Alexandria
# Date created:		18 March 2005
# Whom:			Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	alexandria
PORTVERSION=	0.6.5
PORTREVISION=	3
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
		rubygem-hpricot>=0:${PORTSDIR}/www/rubygem-hpricot

USE_GNOME=	gnomehier intltool
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_GETTEXT=	yes
USE_RUBY=	yes

MAN1=		alexandria.1

DOCS=		NEWS README TODO
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

pre-build:
	${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|' \
		${USR2FIX:S|^|${WRKSRC}/|}
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		's/default_groups.push(\*documentation_installation)//' \
		${WRKSRC}/tasks.rb
.endif

do-build:
	@cd ${WRKSRC} && rake PREFIX=${PREFIX} build

do-install:
	@cd ${WRKSRC} && rake PREFIX=${PREFIX} install

post-install:
	@${MKDIR} ${LOCALBASE}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/schemas/alexandria.schemas \
		${LOCALBASE}/etc/gconf/schemas/
#.if !defined(NOPORTDOCS)
#	@${MKDIR} ${RUBY_MODDOCDIR}
#.for f in ${DOCS}
#	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
#.endfor
#.endif

.include <bsd.port.post.mk>
