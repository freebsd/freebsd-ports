# New ports collection Makefile for:	cook
# Date created:		31 January 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	cook
PORTVERSION=	2.21
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib \
		YACC=yacc

MAN1=	c_incl.1 cook.1 cook_bom.1 cook_lic.1 cook_rsh.1 cookfp.1 cooktime.1 \
	find_libs.1 make2cook.1 roffpp.1
MANPREFIX =	${PREFIX}/share/cook
MANLANG =	"" en
MANCOMPRESSED=	no

# Make sure that the whole directory tree exists.
pre-install:
	${MKDIR} ${PREFIX}/share/cook/en/man1
	${MKDIR} ${PREFIX}/lib/cook/en/LC_MESSAGES

# cook installs extra copies of the manpages in a directory that MANLANG can't
# cope with, so shuffle things around a bit.
post-install:
	@${MKDIR} ${PREFIX}/share/cook/en/man1
	@${MKDIR} ${PREFIX}/share/cook/man/en/man1
.for manpage in ${MAN1}
	@${MV} ${PREFIX}/share/cook/en/man1/${manpage} \
	${PREFIX}/share/cook/man/en/man1/
.endfor
	@${TOUCH} ${PREFIX}/share/cook/en/man1/.not_empty
	@${MKDIR} ${PREFIX}/share/cook/man/man1
.for manpage in ${MAN1}
	@${MV} ${PREFIX}/man/man1/${manpage} ${PREFIX}/share/cook/man/man1/
.endfor
	@echo
	@echo "Add ${PREFIX}/share/cook/man to your MANPATH in order to" \
	"access the manual"
	@echo "pages included with this port."
	@echo

.include <bsd.port.mk>
