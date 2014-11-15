# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim-config
PORTVERSION=	1.0
#PORTREVISION?=	0
CATEGORIES?=	editors

MAINTAINER?=	alfred@FreeBSD.org
COMMENT?=	Default vimrc.

# we are just installing files.
ALL_TARGET=
DISTFILES=
DATADIR=	${PREFIX}/share/vim

do-build:

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${DATADIR}
	
.include <bsd.port.mk>
