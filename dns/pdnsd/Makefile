# New ports collection makefile for:	pdnsd
# Date Created:				27 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pdnsd
PORTVERSION=	1.2
CATEGORIES=	dns
MASTER_SITES=	http://www.phys.uu.nl/~rombouts/pdnsd/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-par

MAINTAINER=	ports@oven.org
COMMENT=	Caching (permanently, writes to disk on exit) DNS proxy-server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB} \
		--enable-ipv6
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN5=		pdnsd.conf.5
MAN8=		pdnsd.8 pdnsd-ctl.8

PDNSDB=		/var/db/pdnsd
DOCSRCDIR=	${WRKSRC}/doc
DOC_FILES=	html/dl.html html/doc.html html/faq.html html/index.html
DOC_FILES+=	txt/faq.txt txt/intro.txt txt/manual.txt

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pdnsd.sh > ${PREFIX}/etc/rc.d/pdnsd.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/pdnsd.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${DOCSRCDIR}/@} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
