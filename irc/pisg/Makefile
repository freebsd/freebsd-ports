# New ports collection makefile for:   pisg
# Date created:        Mon Feb 11 13:02:35 GMT 2002
# Whom:                pgl@instinct.org
#
# $FreeBSD$
#

PORTNAME=	pisg
PORTVERSION=	0.44
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@freebsdcluster.org

USE_REINPLACE=	YES
USE_PERL5=	YES
NO_BUILD=	YES

pre-patch:
	@${REINPLACE_CMD} -e 's|lang.txt|${PREFIX}/share/pisg/lang.txt|; \
		s|layout/|${PREFIX}/share/pisg/layout/|' \
		${WRKSRC}/modules/Pisg.pm
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/pisg

do-install:
	${MKDIR} ${PREFIX}/etc/pisg
	${MKDIR} ${DATADIR}/layout
	${MKDIR} ${DATADIR}/gfx
	${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pisg/Parser/Format
	${INSTALL_DATA} ${WRKSRC}/pisg.cfg ${PREFIX}/etc/pisg/pisg.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/layout/* ${DATADIR}/layout
	${INSTALL_DATA} ${WRKSRC}/lang.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pisg
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pisg/Parser
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/Format/*.pm ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Pisg/Parser/Format
	${INSTALL_SCRIPT} ${WRKSRC}/pisg ${PREFIX}/bin

post-install:
.if !defined(BATCH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "###############################################################################"
	@${ECHO_CMD} "# Please create a pisg config file in ${PREFIX}/etc/pisg                     #"
	@${ECHO_CMD} "# A sample configuration file is installed as pisg.cfg.sample                 #"
	@${ECHO_CMD} "# Remember to move gfx (${DATADIR}/gfx/) to HTML file destination. #"
	@${ECHO_CMD} "###############################################################################"
	@${ECHO_CMD}
.endif

.include <bsd.port.mk>
