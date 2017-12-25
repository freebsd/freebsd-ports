# $FreeBSD$

PORTNAME=		Parse-Pidl
PORTVERSION=		${SAMBA4_VERSION}
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		devel perl5
PKGNAMEPREFIX=		p5-
PKGNAMESUFFIX=		44

COMMENT=		IDL compiler written in Perl

LICENSE=		GPLv3

DEPRECATED=		yes
EXPIRATION_DATE=	2018-01-01

BUILD_DEPENDS=		p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
RUN_DEPENDS:=		${BUILD_DEPENDS}

CONFLICTS=

SAMBA4_PORT=		net/samba44
SAMBA4_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../../${SAMBA4_PORT}
PKGDIR=			${.CURDIR}

USES=			perl5
USE_PERL5=		configure
PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/${DISTNAME}/pidl

post-extract:
			@${RM} -r ${WRKSRC}/lib/Parse/Yapp ${WRKSRC}/lib/wscript_build

.include "${MASTERDIR}/Makefile"
