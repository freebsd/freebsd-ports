PORTNAME=	bnc
DISTVERSION=	2.9.4
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://home.risingnet.net/download/
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple IRC relay proxy with support for virtual hosting

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Unmaintained without upstream distfile and WWW
EXPIRATION_DATE=	2025-05-27

GNU_CONFIGURE=	yes

DOCS=		COPYING Changelog README example.conf
BINS=		bnc mkpasswd
SCRIPTS=	bncchk bncsetup

OPTIONS_DEFINE=	DOCS

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/bncsetup

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.conf ${STAGEDIR}${PREFIX}/etc/bnc.conf.sample

.include <bsd.port.mk>
