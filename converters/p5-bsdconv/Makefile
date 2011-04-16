# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

CATEGORIES+=	perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

MASTERDIR=	${.CURDIR}/../bsdconv
WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/perl
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

.include "${MASTERDIR}/Makefile"
