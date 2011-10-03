# New ports collection makefile for:	devel/p5-Module-CoreList
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-CoreList
PORTVERSION=	2.56
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	See what modules shipped with versions of perl

PERL_CONFIGURE=	yes

MAN1=		p5corelist.1
MAN3=		Module::CoreList.3

SUB_FILES=	pkg-install

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
PLIST_SUB=	BIN_CORELIST=""
.else
PLIST_SUB=	BIN_CORELIST="@comment "
.endif

pre-patch:
	@${MV} ${WRKSRC}/corelist ${WRKSRC}/p5corelist
	@${REINPLACE_CMD} -e 's|^corelist$$|p5corelist|' ${WRKSRC}/MANIFEST
	@${REINPLACE_CMD} -e 's|corelist|p5corelist|' ${WRKSRC}/Makefile.PL ${WRKSRC}/t/pod.t

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.post.mk>
