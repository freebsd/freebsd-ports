# New ports collection makefile for:	Rubyripper
# Date created:				6 Nov 2010
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rubyripper
DISTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	audio sysutils ruby
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Digital audio CD extraction tool for accurate ripping

LICENSE=	GPLv3

# cdparanoia is not really required for the build, but the port would not
# configure without it (ideally, configure script should be fixed instead
# of forcing this superfluous build dependency)
BUILD_DEPENDS=	rxgettext:${PORTSDIR}/devel/rubygem-gettext \
		cdparanoia:${PORTSDIR}/audio/cdparanoia
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cd-discid:${PORTSDIR}/audio/cd-discid

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_RUBY=	yes
INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Rubyripper" "Secure Audio Disc Ripper" \
		"${PORTNAME}" "rrip_gtk2" "Audio;AudioVideo;" false

post-patch:
# fix an apparent typo
	@${REINPLACE_CMD} -e 's,cdparanioa,cdparanoia,' \
		${WRKSRC}/locale/po/bg/rubyripper.po \
		${WRKSRC}/locale/po/ru/rubyripper.po

do-build:
	cd ${WRKSRC} && ${RUBY} configure --update-lang

do-install:
	${INSTALL_DATA} ${WRKSRC}/rr_lib.rb ${RUBY_SITELIBDIR}
.for frontend in cli gtk2
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}_${frontend}.rb \
		${PREFIX}/bin/rrip_${frontend}
.endfor
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png \
		${PREFIX}/share/icons/hicolor/128x128/apps
	cd ${WRKSRC} && ${FIND} . -type f -name \*.mo | ${XARGS} ${TAR} \
		cf - | ${TAR} xf - -C ${PREFIX}/share

.include <bsd.port.mk>
