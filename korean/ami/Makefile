# New ports collection makefile for:	ami
# Version required:     ami-0.4.1
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	ami-0.5.2
PKGNAME=	ko-ami-0.5.2
CATEGORIES=	korean x11
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/

MAINTAINER=	cjh@kr.freebsd.org

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GLIB_CONFIG=${LOCALBASE}/bin/glib12-config \
		GTK_CONFIG=${X11BASE}/bin/gtk12-config

post-build:
	@cd ${WRKSRC}/hanjadic; \
	${MAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hanjadic/hanja-hwp2ami ${PREFIX}/bin

	# patch XLC_LOCALE for ko_KR.EUC(harmless)
	if [ -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE ]; then \
		${MV} -f ${PREFIX}/lib/X11/locale/ko/XLC_LOCALE \
			${PREFIX}/lib/X11/locale/ko/XLC_LOCALE.orig; \
	fi
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/lib/X11/locale/ko/

	${MKDIR} ${PREFIX}/share/doc/ami
	${INSTALL_DATA} ${FILESDIR}/XLC_LOCALE \
		${PREFIX}/share/doc/ami

.for NAME in AUTHORS README NEWS COPYING ChangeLog gtkrc
	${INSTALL_DATA} ${WRKSRC}/${NAME} \
		${PREFIX}/share/doc/ami
.endfor

.include <bsd.port.mk>
