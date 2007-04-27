SET quoted_identifier ON;


CREATE TABLE "domains" (
	"id" INTEGER NOT NULL IDENTITY,
	"name" VARCHAR(255) NOT NULL,
	"type" VARCHAR(6) NOT NULL,
	"master" VARCHAR(40) DEFAULT '' NOT NULL,
	"account" VARCHAR(40) DEFAULT '' NOT NULL,
	"notified_serial" INTEGER NULL,
	"last_check" INTEGER NULL,
	"status" CHAR(1) DEFAULT 'A' NOT NULL,
CONSTRAINT "pk_domains_id"
	PRIMARY KEY ("id"),
CONSTRAINT "unq_domains_name"
	UNIQUE ("name")
);

CREATE INDEX "idx_domains_status_type" ON "domains" ("status","type");



CREATE TABLE "records" (
	"id" INTEGER NOT NULL IDENTITY,
	"domain_id" INTEGER NOT NULL,
	"name" VARCHAR(255) NOT NULL,
	"type" VARCHAR(6) NOT NULL,
	"ttl" INTEGER NULL,
	"prio" INTEGER NULL,
	"content" VARCHAR(255) NOT NULL,
	"change_date" INTEGER NULL,
CONSTRAINT "pk_records_id"
	PRIMARY KEY ("id"),
CONSTRAINT "fk_records_domainid"
	FOREIGN KEY ("domain_id")
	REFERENCES "domains" ("id")
);

CREATE INDEX "idx_records_name_type" ON "records" ("name","type");
CREATE INDEX "idx_records_type" ON "records" ("type");



CREATE TABLE "supermasters" (
	"ip" VARCHAR(40) NOT NULL,
	"nameserver" VARCHAR(255) NOT NULL,
	"account" VARCHAR(40) DEFAULT '' NOT NULL
);

CREATE INDEX "idx_smip_smns" ON "supermasters" ("ip","nameserver");



GRANT SELECT ON "supermasters" TO "powerdns";
GRANT ALL ON "domains" TO "powerdns";
GRANT ALL ON "records" TO "powerdns";
