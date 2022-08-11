PORTNAME=	jdb
PORTVERSION=	1.14
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/JDB/

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	JDB manipulates flat-ASCII databases from shell scripts

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --datadir=${PREFIX}/lib/jdb
SHEBANG_FILES=	db2dcliff dbcol dbcolcreate dbcoldefine dbcoldiff dbcolhisto \
		dbcolize dbcolmerge dbcolmovingstats dbcolmultiscale \
		dbcolneaten dbcolpercentile dbcolrename dbcolscorrelate \
		dbcolsplittocols dbcolsplittorows dbcolstats dbcoltighten \
		dbfilesplit dbformmail dbjoin dblib.pl dblistize dbrow dbmultistats \
		dbrecolize dbrowaccumulate dbrowdiff dbrowenumerate dbroweval \
		dbrowsplituniq dbrowuniq dbsort dbstats dbstripcomments \
		dbstripextraheaders dbstripleadingspace db_to_html_table \
		ipchain_logs_to_db kitrace_to_db tcpdump_to_db

.include <bsd.port.mk>
