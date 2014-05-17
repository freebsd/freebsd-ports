# Created by: Lars Eggert <larse@isi.edu>
# $FreeBSD$

PORTNAME=	jdb
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	JDB manipulates flat-ASCII databases from shell scripts

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --datadir=${PREFIX}/lib/jdb
SHEBANG_FILES=	bin/db2dcliff bin/dbcol bin/dbcolcreate bin/dbcoldefine \
		bin/dbcoldiff bin/dbcolhisto bin/dbcolize bin/dbcolmerge \
		bin/dbcolmovingstats bin/dbcolmultiscale bin/dbcolneaten \
		bin/dbcolpercentile bin/dbcolrename bin/dbcolscorrelate \
		bin/dbcolsplittocols bin/dbcolsplittorows bin/dbcolstats \
		bin/dbcoltighten bin/dbfilesplit bin/dbformmail bin/dbjoin \
		bin/dblistize bin/dbrow bin/dbmultistats bin/dbrecolize \
		bin/dbrowaccumulate bin/dbrowdiff bin/dbrowenumerate \
		bin/dbroweval bin/dbrowsplituniq bin/dbrowuniq bin/dbsort \
		bin/dbstats bin/dbstripcomments bin/dbstripextraheaders \
		bin/dbstripleadingspace bin/db_to_html_table \
		bin/ipchain_logs_to_db bin/kitrace_to_db bin/tcpdump_to_db

.include <bsd.port.mk>
