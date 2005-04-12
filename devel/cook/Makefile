# New ports collection Makefile for:	cook
# Date created:		31 January 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	cook
PORTVERSION=	2.24
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://gd.tuwien.ac.at/softeng/Aegis/cook/

MAINTAINER=	jasone@canonware.com
COMMENT=	Like make(1), but more powerful and clean

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib \
		YACC=yacc
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	c_incl.1 cook.1 cook_bom.1 cook_lic.1 cook_rsh.1 cookfp.1 cooktime.1 \
	find_libs.1 make2cook.1 roffpp.1
MANCOMPRESSED=	no
USE_GETTEXT=	yes

# Make sure that the whole directory tree exists.
pre-install:
	${MKDIR} ${PREFIX}/share/cook/en/man1
	${MKDIR} ${PREFIX}/lib/cook/en/LC_MESSAGES

# cook installs extra copies of the manpages in a directory that MANLANG can't
# cope with.  Delete the extra copies.
post-install:
	@${RM} -rf ${PREFIX}/share/cook/en/man1

.include <bsd.port.mk>
