# New ports collection makefile for:	devtodo
# Date Created:				26 May 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	devtodo
PORTVERSION=	0.1.12
CATEGORIES=	devel
MASTER_SITES=	http://activelysecure.net/~athomas/development/devtodo/download.php?filename=${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	petef@FreeBSD.org

GNU_CONFIGURE=	yes

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
	${INSTALL_DATA} ${WRKSRC}/doc/todorc.example ${PREFIX}/etc/todorc.sample

.include <bsd.port.mk>
