# New ports collection makefile for:	dice
# Date created:		Thu Jan 31 12:07:01 CET 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	hercules
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.conmicro.cx/hercules/

MAINTAINER=	adam@vectors.cx

GNU_CONFIGURE=	yes

post-patch:

	@${PERL} -pi -e 's@lpthread@pthread@g' ${WRKSRC}/configure

do-install:

	@for i in hercules dasdinit dasdisup dasdload dasdls dasdpdsu \
		tapecopy tapemap tapesplt cckd2ckd cckdcdsk ckd2cckd \
		cckdcomp cckdswap hetget hetinit hetmap hetupd dmap2hrc; \
	do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${PREFIX}/bin; \
	done

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/hercules
	@${RM} -f ${WRKSRC}/html/Makefile*
	@for i in ${WRKSRC}/hercules.cnf ${WRKSRC}/html/* ; \
	do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/hercules; \
	done
.endif
	@${CAT} pkg-message

.include <bsd.port.mk>
