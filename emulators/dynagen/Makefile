# New ports collection makefile for:	dynagen
# Date created:		2006-11-07
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	dynagen
PORTVERSION=	0.9.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dyna-gen

MAINTAINER=	trasz@freebsd.org
COMMENT=	Text-based front end for Dynamips

RUN_DEPENDS=	dynamips:${PORTSDIR}/emulators/dynamips

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
ALL_TARGET=	# empty
USE_GCC=	3.4+
USE_DOS2UNIX=	yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynagen ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dynagen.ini ${PREFIX}/etc/dynagen.ini.sample

	@if [ ! -f ${PREFIX}/etc/dynagen.ini ]; then \
		${CP} -p ${PREFIX}/etc/dynagen.ini.sample ${PREFIX}/etc/dynagen.ini ; \
	fi

	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/configspec ${DATADIR}/configspec

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial.htm ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/tutorial_files
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial_files/* ${DOCSDIR}/tutorial_files
.endif
	${MKDIR} ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/sample_labs
	${MKDIR} ${EXAMPLESDIR}/sample_labs/simple1
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple1/simple1.net ${EXAMPLESDIR}/sample_labs/simple1
	${MKDIR} ${EXAMPLESDIR}/sample_labs/multiserver
	${INSTALL_DATA} ${WRKSRC}/sample_labs/multiserver/multiserver.net ${EXAMPLESDIR}/sample_labs/multiserver
	${MKDIR} ${EXAMPLESDIR}/sample_labs/frame_relay
	${INSTALL_DATA} ${WRKSRC}/sample_labs/frame_relay/frame_relay1.net ${EXAMPLESDIR}/sample_labs/frame_relay
	${MKDIR} ${EXAMPLESDIR}/sample_labs/simple2
	${INSTALL_DATA} ${WRKSRC}/sample_labs/simple2/simple2.net ${EXAMPLESDIR}/sample_labs/simple2
	${MKDIR} ${EXAMPLESDIR}/sample_labs/ethernet_switch
	${INSTALL_DATA} ${WRKSRC}/sample_labs/ethernet_switch/ethsw1.net ${EXAMPLESDIR}/sample_labs/ethernet_switch
	${INSTALL_DATA} ${WRKSRC}/sample_labs/all_config_options.txt ${EXAMPLESDIR}/sample_labs

.include <bsd.port.mk>
