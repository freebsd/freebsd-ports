# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rubyripper
DISTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	audio sysutils ruby
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Digital audio CD extraction tool for accurate ripping

LICENSE=	GPLv3

BROKEN=		Does not build with newer rubygem-gettext
DEPRECATED=	Does not build and is deprecated upstream
EXPIRATION_DATE=	2015-07-15

# cdparanoia is not really required for the build, but the port would not
# configure without it (ideally, configure script should be fixed instead
# of forcing this superfluous build dependency)
BUILD_DEPENDS=	rxgettext:${PORTSDIR}/devel/rubygem-gettext \
		cdparanoia:${PORTSDIR}/audio/cdparanoia
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		rubygem-gtk2>=0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cd-discid:${PORTSDIR}/audio/cd-discid

USES=		tar:bzip2 gettext
USE_RUBY=	yes
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Rubyripper" "Secure Audio Disc Ripper" \
		"${PORTNAME}" "rrip_gtk2" "Audio;AudioVideo;" false

post-patch:
# fix an apparent typo
	@${REINPLACE_CMD} -e 's,cdparanioa,cdparanoia,' \
		${WRKSRC}/locale/po/bg/rubyripper.po \
		${WRKSRC}/locale/po/ru/rubyripper.po
	@${REINPLACE_CMD} 's,/usr/local/lib/ruby/site_ruby/1.8,${RUBY_SITELIBDIR},' \
		${WRKSRC}/rubyripper_cli.rb ${WRKSRC}/rubyripper_gtk2.rb

do-build:
	cd ${WRKSRC} && ${RUBY} configure --update-lang

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/rr_lib.rb ${STAGEDIR}${RUBY_SITELIBDIR}
.for frontend in cli gtk2
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}_${frontend}.rb \
		${STAGEDIR}${PREFIX}/bin/rrip_${frontend}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share "-name *.mo"

.include <bsd.port.mk>
