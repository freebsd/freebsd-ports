# ex:ts=8
# Ports collection makefile for:	camomile
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	camomile
PORTVERSION=	0.7.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	SF
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A comprehensive Unicode library for objective caml language

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

PLIST_FILES=	bin/camomilecharmap \
		bin/camomilelocaledef

post-patch:
	@${REINPLACE_CMD} -E -e \
		"s,([[:space:]]*)cp[[:space:]]*-f,\1\$${BSD_INSTALL_DATA}," \
		${WRKSRC}/Makefile.in

post-install:
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
