# Created by: Andriy Gapon
# $FreeBSD$

PORTNAME=	coccinelle
DISTVERSION=	0.2.4rc5
CATEGORIES=	devel
MASTER_SITES=	http://coccinelle.lip6.fr/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Coccinelle is a program matching and transformation engine

USES=		shebangfix gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_PYTHON=	2.5+
USE_OCAML=	3.0+
SHEBANG_FILES=	configure

MAN1=		spatch.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|CAMLreturn0|return 0|' \
		${WRKSRC}/pycaml/pycaml_ml.c
	@${REINPLACE_CMD} 's|shell python|shell ${PYTHON_CMD}|' \
		${WRKSRC}/pycaml/Makefile

.include <bsd.port.mk>
