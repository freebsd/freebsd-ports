# New ports collection makefile for:	devtodo
# Date Created:				26 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	devtodo
PORTVERSION=	0.1.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@databits.net

GNU_CONFIGURE=	Yes

MAN1=	devtodo.1
MLINKS=	devtodo.1 tda.1 devtodo.1 tdd.1 devtodo.1 tde.1 devtodo.1 tdr.1 \
	devtodo.1 todo.1

post-patch:
	@${PERL} -pi -e 's/^\ttest -f.*todorc.*\n//' ${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/share/examples/devtodo
.for file in scripts.sh scripts.tcsh todorc.example
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/examples/devtodo
.endfor

.include <bsd.port.mk>
