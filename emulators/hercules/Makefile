# New ports collection makefile for:	dice
# Date created:		Thu Jan 31 12:07:01 CET 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	hercules
PORTVERSION=	2.16.5
CATEGORIES=	emulators
MASTER_SITES=	http://www.conmicro.cx/hercules/

MAINTAINER=	phk@FreeBSD.org

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

do-install:
.for i in hercules dasdinit dasdisup dasdload dasdls dasdpdsu \
	tapecopy tapemap tapesplt cckd2ckd cckdcdsk ckd2cckd \
	cckdcomp cckdswap hetget hetinit hetmap hetupd dmap2hrc
	${INSTALL_PROGRAM} ${WRKSRC}/$i ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ../hercules.cnf cckddasd.html hercconf.html hercfaq.html \
	hercinst.html herclic.html hercload.html hercnew.html herctcp.html \
	hercules.css index.html
	${INSTALL_DATA} ${WRKSRC}/html/$i ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
