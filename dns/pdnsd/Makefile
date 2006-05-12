# New ports collection makefile for:	pdnsd
# Date Created:				27 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	pdnsd
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.phys.uu.nl/~rombouts/pdnsd/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-par

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Caching (permanently, writes to disk on exit) DNS proxy-server

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-cachedir=${PDNSDB} \
		--disable-src-addr-disc

OPTIONS=	IPV6	"Enable IPv6 support"	on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN5=		pdnsd.conf.5
MAN8=		pdnsd.8 pdnsd-ctl.8

PDNSDB=		/var/db/pdnsd
DOCSRCDIR=	${WRKSRC}/doc
DOC_FILES=	html/dl.html html/doc.html html/faq.html html/index.html
DOC_FILES+=	txt/faq.txt txt/intro.txt txt/manual.txt

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pdnsd.sh > ${PREFIX}/etc/rc.d/pdnsd.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/pdnsd.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${DOCSRCDIR}/@} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
