# New ports collection makefile for: khotot
# Date created:        August 23 2003
# Whom:                Samy Al Bahra <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	khotot
PORTVERSION=	1.0
CATEGORIES=	arabic
MASTER_SITES=	#
DISTFILES=	#
EXTRACT_ONLY=	#

MAINTAINER=	samy@kerneled.com
COMMENT=	A meta-port of the most popular font packages

.if !defined(WITHOUT_MONO)
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/ae_fonts_mono/fonts.dir:${PORTSDIR}/arabic/ae_fonts_mono
.endif

.if !defined(WITHOUT_AEFONTS)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/ae_fonts1/AAHS/fonts.dir:${PORTSDIR}/arabic/ae_fonts_ttf
.endif

.if !defined(WITHOUT_KACST)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/kacst_fonts/fonts.dir:${PORTSDIR}/arabic/kacst_fonts
.endif

NO_BUILD=	yes

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "**********************************************"
	@${ECHO_MSG} "The following make variables can be set to"
	@${ECHO_MSG} "exclude certain font sets:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_MONO - do not install the Arabic PCF"
	@${ECHO_MSG} "		     fonts"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_AEFONTS - do not install the Arabeyes"
	@${ECHO_MSG} "		        truetype Arabic fonts"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_KACST - do not install the truetype"
	@${ECHO_MSG} "		      Arabic fonts created in the"
	@${ECHO_MSG} "		      King AbdulAziz University of"
	@${ECHO_MSG} "		      Riyadh, Saudi Arabia"
	@${ECHO_MSG} "**********************************************"
	@${ECHO_MSG} ""

do-install:
	# This is a meta-port, the do-install target is not needed

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|X11BASE|${X11BASE}|g" \
		${PKGDIR}/pkg-message

.include <bsd.port.mk>
