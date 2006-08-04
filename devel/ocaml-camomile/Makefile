# ex:ts=8
# Ports collection makefile for:	camomile
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	camomile
PORTVERSION=	0.6.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	A comprehensive Unicode library for objective caml language

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/ocaml/bsd.ocaml.mk"

.if ${OSVERSION} < 500000
BROKEN=		Need working <wctype.h>
.endif

post-extract:
	@${CP} ${WRKSRC}/META ${WRKSRC}/META.in
	@${REINPLACE_CMD} -E -e \
		"s,([[:space:]]*)cp[[:space:]]*-f,\1\$${BSD_INSTALL_DATA}," \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
