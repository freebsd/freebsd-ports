# New ports collection makefile for:	shoutcast
# Date created:				15 January 2011
# Whom:					Jarrod Sayers <jarrod@downtools.com.au>
#
# $FreeBSD$
#

PORTNAME=	shoutcast
PORTVERSION=	2.0.0.29
CATEGORIES=	audio net
MASTER_SITES=	http://download.nullsoft.com/shoutcast/tools/
DISTNAME=	sc_serv2_bsd_8_x_07_31_2011

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	SHOUTcast Distributed Network Audio Server

RESTRICTED=	redistribution of software is not permitted
IA32_BINARY_PORT=	yes

USE_RC_SUBR=	shoutcast

CONFLICTS=	linux-shoutcast-[0-9]*
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SHOUTCASTUSER=	${PORTNAME}
SHOUTCASTGROUP=	${PORTNAME}
SHOUTCASTDIR=	/var/run/${PORTNAME}

SHOUTCAST_SUB=	SHOUTCASTUSER=${SHOUTCASTUSER} \
		SHOUTCASTGROUP=${SHOUTCASTGROUP} \
		SHOUTCASTDIR=${SHOUTCASTDIR}

PLIST_SUB=	${SHOUTCAST_SUB}

SUB_FILES=	pkg-message

SUB_LIST=	${SHOUTCAST_SUB}

USERS=		${SHOUTCASTUSER}
GROUPS=		${SHOUTCASTGROUP}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/sc_serv2 directory/d' \
		-e 's#=.*/sc_serv.log#=/var/log/sc_serv.log#g' \
		-e 's#=.*/sc_w3c.log#=/var/log/sc_w3c.log#g' \
		-e 's#=control/#=${SHOUTCASTDIR}/#g' ${WRKSRC}/sc_serv_basic.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${PREFIX}/sbin
	${MKDIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/sc_serv_basic.conf ${ETCDIR}/sc_serv_basic.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sc_serv_debug.conf ${ETCDIR}/sc_serv_debug.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sc_serv_public.conf ${ETCDIR}/sc_serv_public.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sc_serv_relay.conf ${ETCDIR}/sc_serv_relay.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sc_serv_simple.conf ${ETCDIR}/sc_serv_simple.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.txt ${DOCSDIR}/changes.txt
	${INSTALL_DATA} ${WRKSRC}/docs/crossdomain.xml ${DOCSDIR}/crossdomain.xml
	${INSTALL_DATA} ${WRKSRC}/docs/dsp_sc/dsp_sc.txt ${DOCSDIR}/dsp_sc.txt
	${INSTALL_DATA} ${WRKSRC}/docs/dsp_sc/dsp_sc_config.txt ${DOCSDIR}/dsp_sc_config.txt
	${INSTALL_DATA} ${WRKSRC}/docs/getting_started.txt ${DOCSDIR}/getting_started.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2.txt ${DOCSDIR}/sc_serv2.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2_authhash.txt ${DOCSDIR}/sc_serv2_authhash.txt
	${INSTALL_DATA} ${WRKSRC}/docs/sc_serv2_xml_responses.txt ${DOCSDIR}/sc_serv2_xml_responses.txt
	${INSTALL_DATA} ${WRKSRC}/docs/shoutcast_system_overview.txt ${DOCSDIR}/shoutcast_system_overview.txt
.endif

post-install:
	${MKDIR} ${SHOUTCASTDIR}
	@${CHMOD} 0750 ${SHOUTCASTDIR}
	@${CHOWN} ${SHOUTCASTUSER}:${SHOUTCASTGROUP} ${SHOUTCASTDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
