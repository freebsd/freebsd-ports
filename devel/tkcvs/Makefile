#	Ports makefile for tkcvs and tkdiff
#	Versions required: tkvcvs-6.0a1 and tkdiff-1.0b9
#	Date created:	6 July 1996
#	Whom:	Sander Vesik


DISTNAME=	tkcvs-6.0a1
CATEGORIES+=	x11 utility
RUN_DEPENDS=	wish4\.1:${PORTSDIR}/x11/tk41
MASTER_SITES=	ftp://ftp.neosoft.com/languages/tcl/alcatel/code/
MAINTAINER=	sander@haldjas.folklore.ee
WRKSRC=		${WRKDIR}/tkCVS-r6.0a1

post-extract:
	@cp files/Makefile.tkcvs-6.0a1	${WRKSRC}/Makefile
	@cp files/Makefile.tkcvs	${WRKSRC}/tkcvs/Makefile
	@cp files/Makefile.tkdiff	${WRKSRC}/tkdiff/Makefile
	@cp files/Makefile.bitmaps	${WRKSRC}/bitmaps/Makefile
	@cp files/Makefile.inc		${WRKSRC}/Makefile.inc

.include <bsd.port.mk>
