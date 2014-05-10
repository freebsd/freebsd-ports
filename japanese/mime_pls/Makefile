# Created by: n-shigemura@ensure.jp
# $FreeBSD$

PORTNAME=	mime_pls
PORTVERSION=	2.02
PORTREVISION=	1
CATEGORIES=	japanese perl5 mail
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
PKGNAMEPREFIX=	ja-p5-
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Library for MIME encode/decode

USES=		perl5 shebangfix
SHEBANG_FILES=	${BINS}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BINS=		rmime wmime rbody wbody
LIBS=		mimer.pl mimew.pl
PLIST_FILES=	${BINS:C,^,bin/,} ${LIBS:C,^,${SITE_PERL_REL}/,}

do-install:
	${INSTALL_SCRIPT} ${BINS:C,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${SITE_PERL}
	${INSTALL_DATA}   ${LIBS:C,^,${WRKSRC}/,} ${STAGEDIR}${SITE_PERL}

.include <bsd.port.mk>
