# New ports collection makefile for:    h2ps-1.0
# Version required:     1.0
# Date created:         20 May 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.2 1997/09/22 16:21:39 max Exp $
#

DISTNAME=	h2ps-1.0
PKGNAME=	ko-h2ps-${PAPERSIZE}-1.0
CATEGORIES=	korean print
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/applications/

MAINTAINER=	junker@jazz.snu.ac.kr

MANUAL_PACKAGE_BUILD=   PAPERSIZE has to be set to letter a4
MAKE_FLAGS?=	WIDTH=${WIDTH} HEIGHT=${HEIGHT} A4_PAPERSIZE=${A4_PAPERSIZE} -f
MAN1=		h2ps.1

letter::
	${MAKE} PAPERSIZE=letter

letter-install::
	${MAKE} PAPERSIZE=letter install

a4::
	${MAKE} PAPERSIZE=a4

a4-install::
	${MAKE} PAPERSIZE=a4 install


.if !defined(PAPERSIZE)
PAPERSIZE=a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
PAPERSIZE_UNSPECIFIED=	yes
.elif ${PAPERSIZE} == A4 || ${PAPERSIZE} == a4 
PAPERSIZE=a4
WIDTH=8.27
HEIGHT=11.64
A4_PAPERSIZE=1
.elif ${PAPERSIZE} == letter || ${PAPERSIZE} == LETTER
PAPERSIZE=letter
WIDTH=8.5
HEIGHT=11.0
A4_PAPERSIZE=0
.else
PAPERSIZE_INVALID= yes
.endif	# not defined PAPERSIZE


pre-fetch:
.if defined(PAPERSIZE_UNSPECIFIED)
	@echo "Defaulting to ${PAPERSIZE} sized paper."
	@echo ""
	@echo "Set the environment variable PAPERSIZE if you want to use other sizes."
	@echo "Possible values are:  A4 (default) or letter"
.elif defined(PAPERSIZE_INVALID)
	@echo "Error: invalid value for PAPERSIZE: \"${PAPERSIZE}\"" 
	@echo "Possible values are:  A4 (default) or letter"
	@/usr/bin/false
.endif

pre-install:
	@(cd ${WRKSRC}; make install.man)

post-install:
	strip ${PREFIX}/bin/h2ps

.include <bsd.port.mk>
