# ex:ts=8
# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	6.0.a609
CATEGORIES=	editors
MASTER_SITES=	http://a1580.g.akamai.net/7/1580/2064/OpenOffice609/anoncvs.openoffice.org/download/OpenOffice609/
DISTNAME=	oo_609_src
DISTFILES=	oo_609_src${EXTRACT_SUFX} solenv609_linuxintel${EXTRACT_SUFX}

MAINTAINER=	obrien@FreeBSD.org

BROKEN=	'work in progress -- does not work yet'

CONFIGURE_WRKSRC=	${WRKSRC}/config_office

.include <bsd.port.pre.mk>

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@${LN} -fs ${LINUXBASE}/${PREFIX}/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/office52/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignore the error-message. StarOffice5.2 has been installed ; \
		${ECHO} successfully on your system. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} An error occured during StarOffice5.2 install. Please send a mail with debug-output and ; \
		${ECHO} some information about your FreeBSD-environment to mb@imp.ch. Thanks. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
