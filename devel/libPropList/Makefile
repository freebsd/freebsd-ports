# New ports collection makefile for:   libPropListgnome
# Version required:    2.6
# Date Created:                6 December 1998
# Whom:                        Glenn Johnson
#
# $Id$
#

DISTNAME=	libPropList-0.7.1gnome
PKGNAME=	libproplistgnome-0.7.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=    gljohns@bellsouth.net

WRKSRC=		${WRKDIR}/libPropList
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

pre-build:
	${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile
	bison -d ${WRKSRC}/proplist.y -o ${WRKSRC}/proplist.tab.c
	flex -t -B ${WRKSRC}/proplist.l > ${WRKSRC}/lex.pl.c

post-install:
	@${INSTALL_DATA} ${WRKSRC}/proplist.h ${PREFIX}/include/proplistgnome.h
	@if [ "${PORTOBJFORMAT}" = "aout" ]; then \
	${LN} -sf libPropListgnome.so.1.0 ${PREFIX}/lib/libPropListgnome.so; \
	fi
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
