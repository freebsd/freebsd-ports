# ex:ts=8
# New ports collection makefile for:	bnetd
# Date created:		24 April 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	bnetd
PORTVERSION=	0.4.25
PORTREVISION=	0
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.bnetd.org/pub/source/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/bnetd \
		--localstatedir=${PREFIX}/share/bnetd # --with-bits
WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAN1=	bnbot.1 bnchat.1 bnetd.1 bnftp.1 bni2tga.1 bnibuild.1 bniextract.1 \
	bnilist.1 bnpass.1 bnproxy.1 bnstat.1 bntrackd.1 tgainfo.1
MAN5=	bnetd.conf.5 bntext.5
MLINKS=	bntext.5 bnmotd.txt.5 bntext.5 bnnews.txt.5 bntext.5 bnissue.5

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bnetd
	${CP} -R ${WRKSRC}/../docs/ ${PREFIX}/share/doc/bnetd
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/bnetd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/bnetd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/bnetd.sh \
			${PREFIX}/etc/rc.d/bnetd.sh; \
	fi

.include <bsd.port.mk>
