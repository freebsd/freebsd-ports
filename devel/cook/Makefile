# New ports collection Makefile for:	cook
# Date created:		31 January 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	cook
PORTVERSION=	2.30
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=jasone

MAINTAINER=	jasone@FreeBSD.org
COMMENT=	Like make(1), but more powerful and clean

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib \
		YACC=yacc
MAKE_JOBS_UNSAFE=	yes

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
