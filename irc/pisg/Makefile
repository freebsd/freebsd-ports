# New ports collection makefile for:   pisg
# Date created:        Mon Feb 11 13:02:35 GMT 2002
# Whom:                pgl@instinct.org
#
# $FreeBSD$
#

PORTNAME=	pisg
PORTVERSION=	0.66
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A Perl IRC Statistics Generator

USE_REINPLACE=	YES
USE_PERL5=	YES
NO_BUILD=	YES

OPTIONS=	LOGCHARSET "Character set for logfiles" off

.include <bsd.port.pre.mk>

.if defined(WITH_LOGCHARSET)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv
.endif

do-build:

pre-patch:
	@${REINPLACE_CMD} -e 's|lang.txt|${PREFIX}/share/pisg/lang.txt|; \
		s|layout/|${PREFIX}/share/pisg/layout/|' \
		${WRKSRC}/modules/Pisg.pm
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/pisg

do-install:
	${MKDIR} ${PREFIX}/etc/pisg
	${MKDIR} ${DATADIR}/layout
	${MKDIR} ${DATADIR}/gfx
	${MKDIR} ${SITE_PERL}/Pisg/Parser/Format
	${INSTALL_DATA} ${WRKSRC}/pisg.cfg ${PREFIX}/etc/pisg/pisg.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/gfx/* ${DATADIR}/gfx
	${INSTALL_DATA} ${WRKSRC}/layout/* ${DATADIR}/layout
	${INSTALL_DATA} ${WRKSRC}/lang.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg.pm ${SITE_PERL}
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/*.pm ${SITE_PERL}/Pisg
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/*.pm ${SITE_PERL}/Pisg/Parser
	${INSTALL_DATA} ${WRKSRC}/modules/Pisg/Parser/Format/*.pm ${SITE_PERL}/Pisg/Parser/Format
	${INSTALL_SCRIPT} ${WRKSRC}/pisg ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/pisg-doc.txt ${DOCSDIR}/pisg-doc.txt
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} " Please create a pisg config file in ${PREFIX}/etc/pisg"
	@${ECHO_MSG} " A sample configuration file is installed as pisg.cfg.sample"
	@${ECHO_MSG} " Remember to move gfx (${DATADIR}/gfx/) to HTML file destination."
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
