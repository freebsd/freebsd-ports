# ex:ts=8
# New ports collection makefile for: OpenOffice
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	6.0.a638
CATEGORIES=	editors
MASTER_SITES=	http://a2024.g.akamai.net/7/2024/2064/OpenOffice638/anoncvs.openoffice.org/download/OpenOffice638/ \
		http://a2000.g.akamai.net/7/2000/2064/OpenOffice638/anoncvs.openoffice.org/download/OpenOffice638/
DISTNAME=	oo_638_src
#DISTFILES=	oo_638_src${EXTRACT_SUFX} solenv638_linuxintel${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	stlport:${PORTSDIR}/devel/stlport

BROKEN=		'work in progress -- does not work yet'

BZIP2=		yes
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
		${ECHO} Ignore the error-message. OpenOffice has been installed ; \
		${ECHO} successfully on your system. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} An error occured during OpenOffice install. Please send a mail with debug-output and ; \
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
