# New ports collection makefile for:	QUASI88
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

PORTNAME=	quasi88
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nishika@manbow.com
COMMENT=	PC-8801 emulator for X

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
DATAFILES=	_quasi88rc
DOCFILES=	FAQ.TXT FORMAT.TXT GET-IMAGE.TXT HISTORY.TXT MANUAL.TXT QUASI88.TXT

.if !defined(WITH_SOUND)
pre-everything::
	@ ${ECHO_MSG} "===> If you want to enable sound, use \"make WITH_SOUND=yes\"."
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aa
.endif

.if !defined(WITH_DGA)
pre-everything::
	@ ${ECHO_MSG} "===> If you want to enable sound, use \"make WITH_DGA=yes\"."
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ab
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/quasi88
.for i in ${DATAFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/quasi88/
.endfor
.for i in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/quasi88/
.endfor
.endif

.include <bsd.port.mk>
