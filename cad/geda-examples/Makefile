# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	examples
PORTVERSION=	1.4.3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's examples

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
GNU_CONFIGURE=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/geda

.include <bsd.port.pre.mk>

post-patch:
	@$(FIND) ${WRKSRC} -name Makefile.in -exec \
		${REINPLACE_CMD} -e 's,\(^exampledir = \).*,\1${EXAMPLESDIR},g' {} \;

.include <bsd.port.post.mk>
