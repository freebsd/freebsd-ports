# New ports collection makefile for:	intel2gas
# Date created:		12 May 1999
# Whom:			G. Adam Stanislav
#
# $FreeBSD$
#

PORTNAME=	intel2gas
PORTVERSION=	1.2
CATEGORIES=	lang
MASTER_SITES=	http://hermes.terminal.at/intel2gas/ \
		ftp://ftp.scene.org/pub/resources/code/libs/ptc/hermes/intel2gas/

MAINTAINER=	adam@whizkidtech.net

GNU_CONFIGURE=	yes

I2G=	+-.01.list +-.02.list address.syntax data.01.list data.02.list \
	data.04.list discard.01.list main.syntax mathnum.syntax num.syntax \
	op.01.list op.02.list op.04.list op.08.list op.10.list op.20.list \
	reg.01.list reg.02.list reg.04.list reg.08.list reg.10.list \
	reg.20.list section.01.list size.01.list size.02.list size.04.list \
	size.08.list

G2I=	addr.syntax address.syntax data.01.list data.02.list data.04.list \
	main.syntax mathnum.syntax num.syntax section.01.list size.01.list \
	size.02.list size.04.list

I2G2I=	+-.01.list +-.02.list op.01.list op.02.list op.04.list op.08.list \
	op.10.list op.20.list reg.01.list reg.02.list reg.04.list \
	reg.08.list reg.10.list reg.20.list

DOCFILES=	BUGS CHANGES DATAFILES DATAFILES.html README README.html TODO

pre-patch:
	${CP} ${WRKSRC}/README ${WRKSRC}/README.html
	${CP} ${WRKSRC}/DATAFILES ${WRKSRC}/DATAFILES.html

pre-install:
	${MKDIR} ${PREFIX}/share/intel2gas
	${MKDIR} ${PREFIX}/share/intel2gas/i2g
	${MKDIR} ${PREFIX}/share/intel2gas/g2i
	${INSTALL_PROGRAM} ${WRKSRC}/intel2gas ${PREFIX}/bin

do-install:
.for f in ${I2G}
	${INSTALL_DATA} ${WRKSRC}/i2g/${f} ${PREFIX}/share/intel2gas/i2g
.endfor
.for f in ${G2I}
	${INSTALL_DATA} ${WRKSRC}/g2i/${f} ${PREFIX}/share/intel2gas/g2i
.endfor
.for f in ${I2G2I}
	${LN} -fs ${PREFIX}/share/intel2gas/i2g/${f} \
		${PREFIX}/share/intel2gas/g2i/${f}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/intel2gas
.for f in ${DOCFILES}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/share/doc/intel2gas
.endfor
.endif

.include <bsd.port.mk>
